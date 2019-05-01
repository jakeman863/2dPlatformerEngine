#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

/*****************************************************
* Program File Name: AnimationComponent.h
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/19
* Purpose: Handle animations
*
* Input: Sprite size, image size, image, image position.
*
* Output: Produce an animating sprite
***************************************************************/

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Box2D/Box2D.h"
#include "windowInstance.h"

using namespace std;

//Animation class creation
class AnimationComponent
{
	//Private members
	private:
		const int FPS = 60;
		int frameTime;
		SDL_Texture *currentImage;
		SDL_Rect playerRect;
		SDL_Rect playerPosition;
		int frameWidth, frameHeight, textureWidth, textureHeight, numberWide, numberHigh;
		SDL_Renderer* renderTarget;
	//Public members (mainly function prototypes)
	public:
		AnimationComponent(string imageFile, int numWide, int numHigh, int xPos, int yPos, int w, int h, SDL_Renderer* renderT);	
		SDL_Texture *LoadTexture(string filePath, SDL_Renderer *renderTarget);
		void increaseFrameTime();
		void checkFrameTime(b2Vec2 currentPlayerPosition, int width, int height);
	};
#endif