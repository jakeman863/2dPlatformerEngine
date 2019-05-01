/*****************************************************
* Program File Name: AnimationComponent.cpp
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/19
* Purpose: Handle animations
*
* Input: Sprite size, image size, image, image position.
*
* Output: Produce an animating sprite
***************************************************************/

#include "AnimationComponent.h"

/************************************************************************************************************
* Initializes the animation component
*
* parameters: File name, sprite image width, sprite image height, x and y position, and length and width
*
* return: nothing is returned in this constructor
************************************************************************************************************/
AnimationComponent::AnimationComponent(string imageFile, int numWide, int numHigh, int xPos, int yPos, int w, int h)
{
	//Give variables base value
	frameTime = 0;
	currentImage = nullptr;
	playerPosition.x = xPos;
	playerPosition.y = yPos;
	playerPosition.w = w;
	playerPosition.h = h;
	numberWide = numWide;
	numberHigh = numHigh;

	//Load image, and frame and character sizes
	currentImage = LoadTexture(imageFile, renderTarget);
	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
	frameWidth = textureWidth / numWide;
	frameHeight = textureHeight / numHigh;
	playerRect.x = playerRect.y = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;
}

/************************************************************************************************************
* Render the animated sprite
*
* parameters: File path, and current renderer
*
* return: return the rendered texture
************************************************************************************************************/
SDL_Texture* AnimationComponent::LoadTexture(string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str()); //The IMG_Load call is the thing causing the problem
	
	//If else handling the rendering
	if (surface == NULL)
	{
		cout << "Error Surface" << endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == NULL)
		{
			cout << "Error Texture" << endl;
		}
	}

	//Free surface
	SDL_FreeSurface(surface);
	return texture;
}

/************************************************************************************************************
* change frame
*
* parameters: none
*
* return: nothing is returned in this constructor
************************************************************************************************************/
void AnimationComponent :: increaseFrameTime()
{
	frameTime++;
}

/************************************************************************************************************
* Check current frame
*
* parameters: current player position
*
* return: nothing is returned
************************************************************************************************************/
void AnimationComponent :: checkFrameTime(b2Vec2 currentPlayerPosition)
{
	//Check frame
	if (FPS / frameTime == numberWide)
	{
		frameTime = 0;
		playerRect.x += frameWidth;
		if (playerRect.x >= textureWidth)
		{
			playerRect.x = 0;
		}
	}

	//Change position
	playerPosition.x = currentPlayerPosition.x;
	playerPosition.y = currentPlayerPosition.y;

	//Refresh render
	SDL_RenderClear(renderTarget);
	SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
	SDL_RenderPresent(renderTarget);
}