#include "windowInstance.h"

windowInstance::windowInstance()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_VIDEO);

	renderTarget = nullptr;

	window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	//screen = SDL_GetWindowSurface(window);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	world = new b2World(b2Vec2(0.0f, 9.81f));
}

windowInstance::~windowInstance()
{
}
