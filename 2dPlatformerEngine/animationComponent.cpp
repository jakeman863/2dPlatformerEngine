#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(string imageFile, int numWide, int numHigh, int xPos, int yPos, int w, int h)
{
	//0 32
	frameTime = 0;
	currentImage = nullptr;

	playerPosition.x = xPos;
	playerPosition.y = yPos;
	playerPosition.w = w;
	playerPosition.h = h;
	
	//clone 4 2
	numberWide = numWide;
	numberHigh = numHigh;

	currentImage = LoadTexture(imageFile, renderTarget);
	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
	frameWidth = textureWidth / numWide;
	frameHeight = textureHeight / numHigh;
	playerRect.x = playerRect.y = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;
}

SDL_Texture* AnimationComponent::LoadTexture(string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str()); //The IMG_Load call is the thing causing the problem
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

	SDL_FreeSurface(surface);
	return texture;
}

void AnimationComponent :: increaseFrameTime()
{
	frameTime++;
}

void AnimationComponent :: checkFrameTime(b2Vec2 currentPlayerPosition)
{
	if (FPS / frameTime == numberWide)
	{
		frameTime = 0;
		playerRect.x += frameWidth;
		if (playerRect.x >= textureWidth)
		{
			playerRect.x = 0;
		}
	}

	playerPosition.x = currentPlayerPosition.x;
	playerPosition.y = currentPlayerPosition.y;

	//objectBody.SetLinearVelocity(currentPlayerPosition);

	SDL_RenderClear(renderTarget);
	SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
	SDL_RenderPresent(renderTarget);
}