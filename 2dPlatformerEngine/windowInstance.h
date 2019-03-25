#ifndef WINDOWINSTANCE_H
#define WINDOWINSTANCE_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"

class windowInstance
{
public:
	const int WIDTH = 640;
	const int HEIGHT = 480;
	
	b2World* world;
	SDL_Renderer* renderer;
	SDL_Surface* screen;
	SDL_Window* window;
	SDL_Rect cameraRect;

	windowInstance();
	~windowInstance();
};
#endif
