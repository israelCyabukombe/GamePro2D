/********************************************************************
*** Name:Israel Cyabukombe
****File: SpaceShip.cpp
*********************************************************************
*** DESCRIPTION : This will implement the SpaceShip class functions
********************************************************************/

#include "SpaceShip.h"
/********************************************************************
*** FUNCTION :SpaceShip()
*********************************************************************
*** DESCRIPTION :constructor
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
SpaceShip::SpaceShip()
{
}
/********************************************************************
*** FUNCTION :~SpaceShip()
*********************************************************************
*** DESCRIPTION :destructor
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
SpaceShip::~SpaceShip()
{
}
/********************************************************************
*** FUNCTION :  init()
*********************************************************************
*** DESCRIPTION :initializes SpaceShip object attributes
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::init()
{
	GameObject::init(SHIP_BODY_LENGTH / 2, HEIGHT / 2, SHIP_SPEED, SHIP_BOUND_X, SHIP_BOUND_Y);
	setId(PLAYER);
	setAlive(true);
	setCollidable(true);
	lives = 3;
	score = 0;
}
/********************************************************************
*** FUNCTION : moveUp()
*********************************************************************
*** DESCRIPTION : manages SpaceShip moving up by seting decreasing the speed
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::moveUp()
{
	y-= speed;
}
/********************************************************************
*** FUNCTION :moveDown()
*********************************************************************
*** DESCRIPTION :manages SpaceShip moving down by increasing the speed
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::moveDown()
{
	y += speed;
}
/********************************************************************
*** FUNCTION :moveLeft()
*********************************************************************
*** DESCRIPTION : manages SpaceShip moving backwards by decreasing the speed
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::moveLeft()
{
	x -= speed;
}
/********************************************************************
*** FUNCTION :moveRight()
*********************************************************************
*** DESCRIPTION :manages SpaceShip moving forwards by increasing the speed
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::moveRight()
{
	x += speed;
}
/********************************************************************
*** FUNCTION :destroy()
*********************************************************************
*** DESCRIPTION : destroy the SpaceShip if it gets hit a number of times
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::destroy()
{
	GameObject::destroy();
}
/********************************************************************
*** FUNCTION :update()
*********************************************************************
*** DESCRIPTION : udates the ships state
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::update()
{
	GameObject::update();
	if (x < SHIP_BODY_LENGTH / 2) {
		x = SHIP_BODY_LENGTH / 2;
	}
	else if (x > WIDTH / 2) {
		x = WIDTH / 2;
	}
	if (y < SHIP_WING_SPAN) {
		y = SHIP_WING_SPAN;
	}
	else if (y > HEIGHT - SHIP_WING_SPAN) {
		y = HEIGHT - SHIP_WING_SPAN;
	}
}
/********************************************************************
*** FUNCTION :render()
*********************************************************************
*** DESCRIPTION :draw the SpaceShip, in this case it looks like a submarine
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::render()
{
	GameObject::render();
	//gray bar on tail
	al_draw_filled_rounded_rectangle((x+25 - SHIP_BODY_LENGTH)+4, (y+5 - (SHIP_BODY_WIDTH))-1, (x+25 - SHIP_BODY_LENGTH) + 10, (y + (SHIP_BODY_WIDTH-5))-0.5, 3, 3, GRAY);

	//front of submarine
	al_draw_filled_circle(x+50,y, (SHIP_WING_LENGTH/2)+1.5 ,WHITE);
	//gun
	al_draw_filled_rectangle(x + 45, y-5, (x + 25+25)+13,(y + 5), BLACK);
	//top black round rect part
	al_draw_filled_rounded_rectangle(x-15+25,(y-(SHIP_BODY_WIDTH))+3,x+25+(SHIP_BODY_LENGTH/2)-4,y,3,3,BLACK);
	//bottom pointer sticking out of the marine
	al_draw_filled_rounded_rectangle(x +25, (y + (SHIP_BODY_WIDTH))-7, x+25, (y + (SHIP_BODY_WIDTH / 2)) - 4, 5, 5, BLACK); //GOT LUCKY ON THIS ONE
	//gray top most part of the marine
	//al_draw_filled_rectangle(x+25, y - (SHIP_BODY_WIDTH+10), x +25 + (SHIP_BODY_LENGTH / 2) - 10, y - (SHIP_BODY_WIDTH),GRAY);
	//Main body gray rectangle
	al_draw_filled_rectangle(x+25-(SHIP_BODY_LENGTH/1.5),(y-(SHIP_BODY_WIDTH/1.5)), x +25+ (SHIP_BODY_LENGTH /1.5), (y + (SHIP_BODY_WIDTH / 1.5)),GRAY);
	//triangular white tail of the rectangle
	al_draw_filled_triangle(x+25 - (SHIP_BODY_LENGTH / 1.5), y - (SHIP_BODY_WIDTH / 1.5), x+25 - (SHIP_BODY_LENGTH / 1.5), (y +(SHIP_BODY_WIDTH-6)),x+25-(SHIP_BODY_LENGTH+5),y,WHITE);
	//gray bar on tail
	al_draw_filled_rounded_rectangle(x+25 - SHIP_BODY_LENGTH, y+5 - (SHIP_BODY_WIDTH), (x+25 - SHIP_BODY_LENGTH)+7, y + (SHIP_BODY_WIDTH-5), 3, 3, GRAY);

	


}
/********************************************************************
*** FUNCTION :collided(const Id objectId)
*********************************************************************
*** DESCRIPTION : manages SpaceShip collisions with enemy, and sets the nu
***					mber of lives accordingly
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void SpaceShip::collided(const Id objectId)
{
	GameObject::collided(objectId);
	if (objectId == ENEMY) {
		lives--;
	}
}
