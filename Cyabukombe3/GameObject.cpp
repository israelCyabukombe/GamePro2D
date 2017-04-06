/********************************************************************
*** Name:Israel Cyabukombe
****File: Object.cpp
*********************************************************************
*** DESCRIPTION : This will implement the GameObject class functions
********************************************************************/
#include "GameObject.h"

/********************************************************************
*** FUNCTION :GameObject()
*********************************************************************
*** DESCRIPTION : constructor, initializes variable
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
GameObject::GameObject() {
	x = 0;
	y = 0;
	speed = 0;
	boundX = 0;
	boundY = 0;
	alive = true;
	collidable = true;
}
/********************************************************************
*** FUNCTION : ~GameObject()
*********************************************************************
*** DESCRIPTION : Destructor, destroy the GameObject when the game is done
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
GameObject::~GameObject() {
}
/********************************************************************
*** FUNCTION :init(const int x, const int y, const int speed,
				const int boundX, const int boundY)
*********************************************************************
*** DESCRIPTION :  initializes x and y , speed an object bounds
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void GameObject::init(const int x, const int y, const int speed,
	const int boundX, const int boundY) {
	GameObject::x = x;
	GameObject::y = y;
	GameObject::speed = speed;
	GameObject::boundX = boundX;
	GameObject::boundY = boundY;
}
/********************************************************************
*** FUNCTION :destroy()
*********************************************************************
*** DESCRIPTION : destroys a game object when enemy collides
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void GameObject::destroy() {
}
/********************************************************************
*** FUNCTION :update()
*********************************************************************
*** DESCRIPTION : updates the game objects state
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/

void GameObject::update() {
}
/********************************************************************
*** FUNCTION : render
*********************************************************************
*** DESCRIPTION : draws object to the screen
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void GameObject::render() {
}
/********************************************************************
*** FUNCTION : collided(const Id objectId)
*********************************************************************
*** DESCRIPTION : manages object collisions
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void GameObject::collided(const Id objectId) {
}
/********************************************************************
*** FUNCTION : isCollidable()
*********************************************************************
*** DESCRIPTION :  returns true or false if an object is collidable
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
bool GameObject::isCollidable() const {
	return alive && collidable;
}
/********************************************************************
*** FUNCTION :checkCollision(const GameObject *otherObject)
*********************************************************************
*** DESCRIPTION : will check collision using the objects outer bounds
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
bool GameObject::checkCollision(const GameObject *otherObject) const {
	int oX = otherObject->getX();
	int oY = otherObject->getY();
	int obX = otherObject->getBoundX();
	int obY = otherObject->getBoundY();
	if( x + boundX > oX - obX && x - boundX < oX + obX && y + boundY > oY - obY && y - boundY < oY + obY) {
		return true;
	}
	else {
		return false;
	}
}
