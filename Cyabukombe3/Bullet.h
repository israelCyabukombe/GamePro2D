#pragma once
/********************************************************************
*** Name:Israel Cyabukombe
****CLass: GAME PROGRAMMING
****File:	Bullet.h
*********************************************************************
*** DESCRIPTION :  The Bullet class is a derived class of the GameObject
************************************************************/

#include"GameObject.h"
class Bullet : public GameObject {
	private:
/************************************************************
***Function: scorePoimt
*************************************************************
***Description: will set the score when enemy is destroyed
*************************************************************/
		void(*scorePoint) (void);

	public:
/************************************************************
***Function: Bullet(const int, const int , void)
*************************************************************
***Description:this will construct the bullet object
*************************************************************/
		Bullet(const int x, const int y, void(*scorePoint)(void));
/************************************************************
***Function: ~Bullet();
*************************************************************
***Description: destructor
*************************************************************/
		~Bullet();
/************************************************************
***Function: destroy();
*************************************************************
***Description: will destroy the bullet object
*************************************************************/
		void destroy();
/************************************************************
***Function:update();
*************************************************************
***Description: update the state of the bullet depending on 
				wether it collides with enemy or border
*************************************************************/
		void update();
/************************************************************
***Function:render();
*************************************************************
***Description:will display the bullet drawing on the screen
*************************************************************/
		void render();
/************************************************************
***Function: collided(const Id objectId)
*************************************************************
***Description: set the state of the bullet depending on the 
				object collided with it.
*************************************************************/
		void collided(const Id objectId);
};