#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"

class Player: public GameObject
{
	private:
		b2Body* myRect;
	public:
		void drawLine(SDL_Surface* dest, int x0, int y0, int x1, int y1);
		void rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle);
		b2Body* addRectangle(int x, int y, int w, int h, bool dyn = true);
		void drawSquare(b2Vec2* points, b2Vec2 center, float angle);
		void initialize();
		void displayIt();
};

#endif