/********************************************************************
*** Name:Israel Cyabukombe
****File: Bullet.cpp
*********************************************************************
*** DESCRIPTION : This will implement the Bullet class functions
********************************************************************/
#include "Bullet.h"
/********************************************************************
*** FUNCTION :Bullet(const int x, const int y, void(*scorePoint)(void))
*********************************************************************
*** DESCRIPTION : constructs Bullet object
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
Bullet::Bullet(const int x, const int y, void(*scorePoint)(void))
{
	GameObject::init(x, y, BULLET_SPEED, BULLET_BOUND_X, BULLET_BOUND_Y);
	setId(BULLET);
	setCollidable(true);
	Bullet::scorePoint = scorePoint;
}
/********************************************************************
*** FUNCTION :~Bullet()
*********************************************************************
*** DESCRIPTION :Destructor
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
Bullet::~Bullet()
{
}
/********************************************************************
*** FUNCTION :destroy()
*********************************************************************
*** DESCRIPTION : destroys the gameObject
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Bullet::destroy()
{
	GameObject::destroy();
}
/********************************************************************
*** FUNCTION :update()
*********************************************************************
*** DESCRIPTION : updates the state of the bullet depending on collisions
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Bullet::update()
{
	GameObject::update();
	x += speed;
	if (x > WIDTH) {
		collided(BORDER);
	}
}
/********************************************************************
*** FUNCTION : render()
*********************************************************************
*** DESCRIPTION : draws the bullet object
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Bullet::render()
{
	GameObject::render();
	al_draw_filled_circle(x+30, y, BULLET_RADIUS, BULLET_COLOR);
}
/********************************************************************
*** FUNCTION collided(const Id objectId)
*********************************************************************
*** DESCRIPTION : sets the state of bullet when it collides and also sets the score point
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void Bullet::collided(const Id objectId)
{
	GameObject::collided(objectId);
	if (objectId == ENEMY|| objectId == BORDER)
	{
		setAlive(false);
	}
	if (objectId == ENEMY) {
		scorePoint();
	}
}
