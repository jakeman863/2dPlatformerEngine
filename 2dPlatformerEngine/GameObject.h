#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"

class GameObject
{
	private:

	public:
		//Constants across all gameobjects
		const int WIDTH = 640;
		const int HEIGHT = 480;
		const float MetersToPixels = 20;
		const float PixelsToMeters = 1 / MetersToPixels;
		b2World* world;
		SDL_Surface* screen;
		SDL_Window* window;
		void putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b);
		void swapValue(int& a, int& b);
};

#endif