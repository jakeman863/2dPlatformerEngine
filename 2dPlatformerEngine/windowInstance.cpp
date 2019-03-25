#include "windowInstance.h"

windowInstance::windowInstance()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	screen = SDL_GetWindowSurface(window);
	cameraRect = { 0, 0, 640, 480 };
	world = new b2World(b2Vec2(0.0f, 9.81f));
}


windowInstance::~windowInstance()
{
}
