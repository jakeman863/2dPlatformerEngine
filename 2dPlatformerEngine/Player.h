#ifndef PLAYER_H
#define PLAYER_H
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

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"
#include "AnimationComponent.h"

//Class
class Player : public GameObject
{
	//Public attributes
	public:
		AnimationComponent *animComp;
		Player(windowInstance* thisWindow, int oID, string fileName, int numWide, int numHigh, int x, int y, int w, int h);
		virtual void beginningOperation();
		virtual void updateAnimation(b2Vec2 currentPlayerPosition);
};
#endif