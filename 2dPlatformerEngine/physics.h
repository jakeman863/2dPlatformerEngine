#ifndef PHYSICS_H
#define PHYSICS_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"

class physics
{
	private:
		const int WIDTH = 640;
		const int HEIGHT = 480;
		const float MetersToPixels = 20;
		const float PixelsToMeters = 1 / MetersToPixels;
		b2World* world;
		SDL_Surface* screen;
		SDL_Window* window;
		b2Body* myRect;
	public:
		void putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b);
		void swapValue(int& a, int& b);
		void drawLine(SDL_Surface* dest, int x0, int y0, int x1, int y1);
		void rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle);
		b2Body* addRectangle(int x, int y, int w, int h, bool dyn = true);
		void drawSquare(b2Vec2* points, b2Vec2 center, float angle);
		void initialize();
		void displayIt();
		void go();
};

#endif