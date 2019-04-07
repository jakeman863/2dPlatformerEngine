#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "windowInstance.h"
#include "AnimationComponent.h"

class GameObject
{
	private:
		const float MetersToPixels = 20;
		const float PixelsToMeters = 1 / MetersToPixels;
	public:
		
		b2Body* myRect;
		windowInstance* windowRef;
		
		GameObject(windowInstance* thisWindow);
		GameObject();

		void drawLine(SDL_Surface *dest, int x0, int y0, int x1, int y1); 
		void rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle);
		b2Body* addRectangle(int x, int y, int w, int h, bool dyn);
		void drawSquare(b2Vec2* points, b2Vec2 center, float angle);
		void drawSquare2(b2Vec2* points, b2Vec2 center, float angle);
		void displayIt();
		void displayIt2();
		void putPixel(SDL_Surface *dest, int x, int y, int r, int g, int b);
		void swapValue(int& a, int& b);
		
};
#endif