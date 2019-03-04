#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"

void GameObject::putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b)
{
	if (x >= 0 && x < dest->w && y >= 0 && y < dest->h)
	{
		((Uint32*)dest->pixels)[y*dest->pitch / 4 + x] = SDL_MapRGB(dest->format, r, g, b);
	}
}

void GameObject::swapValue(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}