#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "windowInstance.h"

class GameObject
{
	private:
		const float MetersToPixels = 20;
		const float PixelsToMeters = 1 / MetersToPixels;
		

	public:
		b2Body* myRect;
		b2Color m_color;
		windowInstance* windowRef;

		GameObject(windowInstance* thisWindow);
		GameObject();

		void drawLine(SDL_Surface* dest, int x0, int y0, int x1, int y1);
		void rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle);
		b2Body* addRectangle(int x, int y, int w, int h, bool dyn, b2Color color, uint16 categoryBits, uint16 maskBits, bool hitbox);
		b2Body* addRectangle(int x, int y, int w, int h, bool dyn);
		void drawSquare(b2Vec2* points, b2Vec2 center, float angle);
		void displayIt();
		void putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b);
		void swapValue(int& a, int& b);
};

enum _entityCategory {
	BOUNDARY = 0x0001,
	PLAYER = 0x0002,
	ENEMY = 0x0004,
	HITBOX = 0x0006,
	NPC = 0x0008
};
#endif