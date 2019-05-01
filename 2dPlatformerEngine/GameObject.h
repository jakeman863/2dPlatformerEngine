#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

/*****************************************************
* Program File Name: GameObject.h
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/17
* Purpose: Create basic game objects
*
* Input: Position, size, window, ID
*
* Output: Produce a game object
***************************************************************/

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "windowInstance.h"
#include "AnimationComponent.h"

//Class
class GameObject
{
	//Private members
	private:
		const float MetersToPixels = 20;
		const float PixelsToMeters = 1 / MetersToPixels;
	//Public members
	public:	
		b2Body* myRect;
		windowInstance* windowRef;
		int objectID;
		int xVal;
		int yVal;
		int wVal;
		int hVal;
		string fName;
		int nWideVal;
		int nHighVal;
		bool isDynamic;
		
		GameObject();
		GameObject(windowInstance* thisWindow, int oID, int x, int y, int w, int h, bool dyn);
		virtual void beginningOperation();
		void drawLine(SDL_Surface *dest, int x0, int y0, int x1, int y1); 
		void rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle);
		b2Body* addRectangle(int x, int y, int w, int h, bool dyn);
		void drawSquare(b2Vec2* points, b2Vec2 center, float angle);
		void drawSquare2(b2Vec2* points, b2Vec2 center, float angle);
		void displayIt();
		void displayIt2();
		void putPixel(SDL_Surface *dest, int x, int y, int r, int g, int b);
		void swapValue(int& a, int& b);
		virtual void updateAnimation(b2Vec2 currentPlayerPosition);
};
#endif