#ifndef WINDOWINSTANCE_H
#define WINDOWINSTANCE_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "windowInstance.h"

class windowInstance
{
public:
	const int WIDTH = 640;
	const int HEIGHT = 480;
	
	b2World* world;
	SDL_Surface* screen;
	SDL_Window* window;

	windowInstance();
	~windowInstance();
};
#endif
