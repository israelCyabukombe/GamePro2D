/********************************************************************
*** Name:Israel Cyabukombe
****File: Comet.cpp
*********************************************************************
*** DESCRIPTION : This will implement the Comet class functions
********************************************************************/
#include "Comet.h"
/********************************************************************
*** FUNCTION : Comet(const int x, const int y, void(*takeLife)(void))
*********************************************************************
*** DESCRIPTION : constructor
*** OUTPUT ARGS :   int x,y, void =(*takeLife)
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
Comet::Comet(const int x, const int y, void(*takeLife)(void))
{
	GameObject::init(x, y, COMET_SPEED, COMET_BOUND_X, COMET_BOUND_Y);
	setId(ENEMY);
	setCollidable(true);
	Comet::takeLife = takeLife;
}
/********************************************************************
*** FUNCTION :~Comet()
*********************************************************************
*** DESCRIPTION : It will destroy the class at the end of the program
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
Comet::~Comet()
{
}
/********************************************************************
*** FUNCTION :destroy()
*********************************************************************
*** DESCRIPTION : IT will destroy the comet object when it's hit
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Comet::destroy()
{
	GameObject::destroy();
}
/********************************************************************
*** FUNCTION :Update
*********************************************************************
*** DESCRIPTION :  
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Comet::update()
{
	GameObject::update();
	x -= speed;
	if (x < 0) {
		collided(BORDER);
	}
}
/********************************************************************
*** FUNCTION :render()
*********************************************************************
*** DESCRIPTION : draws the comet to the screen in this case fish looking one
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Comet::render()
{
	GameObject::render();
	al_draw_filled_ellipse(x, y, COMET_RADIUS1,COMET_RADIUS2, MAROON);
	al_draw_filled_triangle(x+COMET_RADIUS1, y, x + COMET_RADIUS1+10, y-(COMET_RADIUS2/2)-2, x + COMET_RADIUS1 + 10, y+(COMET_RADIUS2/2)+4, MAROON);
	//eyes
	al_draw_filled_circle(x - (COMET_RADIUS1 / 2), y - (COMET_RADIUS2 / 2),COMET_RADIUS1/10, WHITE);
	al_draw_filled_circle(x - (COMET_RADIUS1 / 2)-1, y - (COMET_RADIUS2 / 2), COMET_RADIUS1/12, BLACK);
}
/********************************************************************
*** FUNCTION : collide(const Id objectId)
*********************************************************************
*** DESCRIPTION :  determines when object has collided and either setAlive or takeLife
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
 void Comet::collided(const Id objectId)
{
	GameObject::collided(objectId);
	if (objectId != ENEMY) {
		setAlive(false);
	}
	if (objectId == BORDER) {
		takeLife();
	}
}
