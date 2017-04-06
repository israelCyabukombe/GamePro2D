#pragma once
/********************************************************************
*** Name:Israel Cyabukombe
****CLass: GAME PROGRAMMING
****File: Comet.h
*********************************************************************
*** DESCRIPTION :  The Comet class is a derived class of the GameObject
********************************************************************/
#include"GameObject.h"

class Comet : public GameObject {
private:
/************************************************************
***Function:void(*takeLife)(void)
*************************************************************
***Description: decrements the lives of the spaceShip when it 
				collides with the commet object
*************************************************************/
	void(*takeLife)(void);
public:
/************************************************************
***Function:Comet(const int x, const int y, void(*takeLife)(void))
*************************************************************
***Description: will construct the comet object
*************************************************************/
	Comet(const int x, const int y, void(*takeLife)(void));
/************************************************************
***Function: ~Comet()
*************************************************************
***Description: Comet destructor called when game ends
*************************************************************/
	~Comet();
/***************************************************** *******
***Function:destroy ();
*************************************************************
***Description: function destroys the comet object
*************************************************************/
	void destroy();
/************************************************************
***Function: update();
*************************************************************
***Description: function updates the state of the comet accor
				ding to the collisions
*************************************************************/
	void update();
/************************************************************
***Function: render();
*************************************************************
***Description:
*************************************************************/
	void render();
/************************************************************
***Function: collided(const Id objectId)
*************************************************************
***Description: determines collisions and sets the comet obje
				ct accordingly
*************************************************************/
	void collided(const Id objectId);

};