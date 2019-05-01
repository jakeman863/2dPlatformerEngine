/*****************************************************
* Program File Name: Player.h
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/17
* Purpose: Create player object
*
* Input: Mainly game object characteristics
*
* Output: Player object
***************************************************************/

#include "Player.h"

/************************************************************************************************************
* sets the variables to there default values
*
* parameters: window, object ID, animation file name, num wide, num high, x, y, w, and h
*
* return: nothing is returned in this constructor
************************************************************************************************************/
Player::Player(windowInstance* thisWindow, int oID, string fileName, int numWide, int numHigh, int x, int y, int w, int h)
{
	windowRef = thisWindow;
	objectID = oID;
	xVal = x;
	yVal = y;
	wVal = w;
	hVal = h;
	nWideVal = numWide;
	nHighVal = numHigh;
	fName = fileName;
}

/************************************************************************************************************
* Conducts base operation
*
* parameters: there are no parameters
*
* return: nothing is returned
************************************************************************************************************/
void Player::beginningOperation()
{
	animComp = new AnimationComponent(fName, nWideVal, nHighVal, xVal, yVal, wVal, hVal, windowRef->renderTarget); //"clone.png", 4, 2, 100, 200, 50, 50
	myRect = addRectangle(xVal, yVal, wVal, hVal, true);
	//b2Color red(1, 0, 0);
	//myRect = addRectangle(100, 200, 50, 50, true, red , PLAYER, BOUNDARY | HITBOX, false);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(7.0f);
}

/************************************************************************************************************
* Updates the animation
*
* parameters: Current player position
*
* return: nothing is returned in this constructor
************************************************************************************************************/
void Player::updateAnimation(b2Vec2 currentPlayerPosition)
{
	animComp->increaseFrameTime();
	animComp->checkFrameTime(currentPlayerPosition, wVal, hVal);
}