#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"

// Only a test function
void changeRenderer(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	// Flags to change window properties (Adding more flags requires | between each flag)
	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

	// Creates a window (640 x 480) with the title "Game Window"
	SDL_Window *window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, flags);
	// Simple rendering for testing
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	
	// Renderer Test function (Sets random background color)
	changeRenderer(renderer);

	SDL_Rect player;
	player.x = 50;
	player.y = 50;
	player.w = 50;
	player.h = 50;
	
	SDL_RenderDrawRect(renderer, &player);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderPresent(renderer);

	// Main Window Loop
	bool quit = false;
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
			}
		}

		// Take Input Here

		// Update

		// Draw

		// Renderer Test function
		//changeRenderer(renderer);
	}

	return 0;
}