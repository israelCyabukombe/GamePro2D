#pragma once
/********************************************************************
*** Name:Israel Cyabukombe
****CLass: GAME PROGRAMMING
****ASSIGNEMENT: 3
*********************************************************************
*** DESCRIPTION :  This class is a parent class of all the Objects that are
going to be used in this game
********************************************************************/
#include "Globals.h"

class GameObject {
	private:
		Id   id;
		bool alive;
		bool collidable;
	protected:
		int  x;
		int  y;
		int  speed;
		int  boundX;
		int  boundY;
	public:
/************************************************************
***Function: GameObject()
*************************************************************
***Description: costructs a game object when the class object
				is defined
*************************************************************/
		GameObject();
/************************************************************
***Function:~GameObject()
*************************************************************
***Description: destructoys the game Object when the program
				terminates
*************************************************************/
		~GameObject();
/************************************************************
***Function:getId()
*************************************************************
***Description: gets the game object type
*************************************************************/
		Id   getId() const {return id;}
/************************************************************
***Function:getAlive()
*************************************************************
***Description: gets the state of Alive "false or true"
*************************************************************/
		bool getAlive() const {return alive;}
/************************************************************
***Function: getCollidable()
*************************************************************
***Description: gets the state collidable 
*************************************************************/
		bool getCollidable() const {return collidable;}
/************************************************************
***Function:getX()
*************************************************************
***Description:gets the x coordinate of the game object
*************************************************************/
		int  getX() const {return x;}
/************************************************************
***Function:getY()
*************************************************************
***Description: gets the y coordinate of the game object
*************************************************************/
		int  getY() const {return y;}
/************************************************************
***Function:getSpeed()
*************************************************************
***Description: gets the speed of the game object
*************************************************************/
		int  getSpeed() const {return speed;}
/************************************************************
***Function:getBoundX()
*************************************************************
***Description: gets the x bound of the object
*************************************************************/
		int  getBoundX() const {return boundX;}
/************************************************************
***Function: getBoundY()
*************************************************************
***Description: gets the y bound of the object
*************************************************************/
		int  getBoundY() const {return boundY;}
/************************************************************
***Function:setId(const Id id)
*************************************************************
***Description: sets the object type "PLAYER ENEMY OR BULLET ..."
*************************************************************/
		void setId(const Id id) {GameObject::id = id;}
/************************************************************
***Function:setAlive(const bool alive) 
*************************************************************
***Description: sets the state Alive of the object 
				"false or true"     " dead or alive"
*************************************************************/
		void setAlive(const bool alive) {GameObject::alive = alive;}
/************************************************************
***Function:setCollidable(const bool collidable)
*************************************************************
***Description: sets the state collidable
*************************************************************/
		void setCollidable(const bool collidable){GameObject::collidable = collidable;}
/************************************************************
***Function:setX(const int x)
*************************************************************
***Description: sets the object's  x coordinate
*************************************************************/
		void setX(const int x) {GameObject::x = x;}
/************************************************************
***Function:setY(const int y) 
*************************************************************
***Description: sets the objects's y coordinate 
*************************************************************/
		void setY(const int y) {GameObject::y = y;}
/************************************************************
***Function:  setSpeed(const int speed)
*************************************************************
***Description: sets the object's speed 
*************************************************************/
		void setSpeed(const int speed) {GameObject::speed = speed;}
/************************************************************
***Function:setBoundX(const int boundX)
*************************************************************
***Description: sets the object's x bound
*************************************************************/
		void setBoundX(const int boundX) {GameObject::boundX = boundX;}
/************************************************************
***Function:setBoundY(const int boundY)
*************************************************************
***Description:sets the object's y bound
*************************************************************/
		void setBoundY(const int boundY) {GameObject::boundY = boundY;}
/************************************************************
***Function:nit(const int x, const int y, const int speed,const int boundX, const int boundY)
*************************************************************
***Description: intializes the game object
*************************************************************/
		void init(const int x, const int y, const int speed,const int boundX, const int boundY);
/************************************************************
***Function:destroy()
*************************************************************
***Description: The function destroys the game object
*************************************************************/
		virtual void destroy();
/************************************************************
***Function:update()
*************************************************************
***Description: the function updates the game object accordingly
*************************************************************/
		virtual void update();
/************************************************************
***Function:render()
*************************************************************
***Description:The function will draw the game object on the 
				screen
*************************************************************/
		virtual void render();
/************************************************************
***Function: collided(const Id objectId)
*************************************************************
***Description: determines wether the game object has 
				collided
*************************************************************/
		virtual void collided(const Id objectId);
/************************************************************
***Function:isCollidable()
*************************************************************
***Description: returns the objects state to collide with 
				other game objects
*************************************************************/
		bool isCollidable() const;
/************************************************************
***Function:checkCollision(const GameObject *otherObject) const
*************************************************************
***Description: determines if game object has collided with 
				other game objects and returns the state
*************************************************************/
		bool checkCollision(const GameObject *otherObject) const;
};
