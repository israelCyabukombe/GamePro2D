#pragma once
/********************************************************************
*** Name:Israel Cyabukombe
****CLass: GAME PROGRAMMING
****File: SpaceShip.h
*********************************************************************
*** DESCRIPTION :  The SpaceShip class is a derived class of the GameObject
********************************************************************/

#include"GameObject.h"
class SpaceShip : public GameObject {

private:
	int lives;
	int score;

public:
/************************************************************
***Function:SpaceShip()
*************************************************************
***Description: constructor automatically called when the 
				SpaceShip class is defined in main
*************************************************************/
	SpaceShip();
/************************************************************
***Function:~SpaceShip()
*************************************************************
***Description: destroctor destroys the class objects at the 
				end of the program
*************************************************************/
	~SpaceShip();
/************************************************************
***Function:getLives()
*************************************************************
***Description: gets the SpaceShip object's lives
*************************************************************/
	int getLives() const { return lives; }
/************************************************************
***Function:getScore()
*************************************************************
***Description:gets the SpaceShip's object's score
*************************************************************/
	int getScore() const { return score; }
/************************************************************
***Function:setLives()
*************************************************************
***Description: sets the SpaceShip's object's lives
*************************************************************/
	void setLives(const int lives) { SpaceShip::lives = lives; }
/************************************************************
***Function:setScore()
*************************************************************
***Description:sets the SpaceShip's object's lives
*************************************************************/
	void setScore(const int score) { SpaceShip::score = score; }
/************************************************************
***Function: init()
*************************************************************
***Description: initializes the SpaceShip
*************************************************************/
	void init();
/************************************************************
***Function:moveUp()
*************************************************************
***Description: controlls the SpaceShip moving up
*************************************************************/
	void moveUp();
/************************************************************
***Function: moveDown()
*************************************************************
***Description:controlls the SpaceShip moving down
*************************************************************/
	void moveDown();
/************************************************************
***Function:moveLeft()
*************************************************************
***Description:controlls the SpaceShip moving left
*************************************************************/
	void moveLeft();
/************************************************************
***Function:moveRight()
*************************************************************
***Description:controlls the SpaceShip moving right
*************************************************************/
	void moveRight();
/************************************************************
***Function:destroy()
*************************************************************
***Description:destroys the SpaceShip
*************************************************************/
	void destroy();
/************************************************************
***Function: update()
*************************************************************
***Description: updates the state of the SpaceShip
*************************************************************/
	void update();
/************************************************************
***Function:render()
*************************************************************
***Description: draws the shape of the SpaceShip on the screen
*************************************************************/
	void render();
/************************************************************
***Function:collided(const Id objectId)
*************************************************************
***Description:  determines if the SpaceShip object has collided
*************************************************************/
	void collided(const Id objectId);

};