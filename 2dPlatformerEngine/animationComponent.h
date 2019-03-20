#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "windowInstance.h"
using namespace std;

class animationComponent : public windowInstance
{
private:
	const int FPS = 60; //This block is things I changed
	int frameTime;
	SDL_Renderer *renderTarget;
	SDL_Texture *currentImage;
	SDL_Rect playerRect;
	SDL_Rect playerPosition;
	int frameWidth, frameHeight, textureWidth, textureHeight, numberWide, numberHigh;
public:
	animationComponent(string imageFile, int numWide, int numHigh, int xPos, int yPos, int w, int h);
	SDL_Texture *LoadTexture(string filePath, SDL_Renderer *renderTarget);
	void increaseFrameTime();
	void checkFrameTime();
};
#endif