#include "Player.h"
#include "GameObject.h"
#include "windowInstance.h"

int main(int argc, char *argv[])
{
	// Create World/Window
	windowInstance* newWindow = new windowInstance();
	// Instantiate an object
	GameObject* ground = new GameObject(newWindow);
	Player* player = new Player(newWindow);

	Uint32 start;
	SDL_Event event;
	bool running = true;

	while (running)
	{
		b2Vec2 vel = player->myRect->GetLinearVelocity();;

		//newObject.myRect->GetLinearVelocity();

		start = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_d:
					vel.x = 75;
					player->myRect->SetLinearVelocity(vel);
					break;
				case SDLK_a:
					vel.x = -75;
					player->myRect->SetLinearVelocity(vel);
					break;
				case SDLK_SPACE:
					if (vel.y == 0)
					{
						player->myRect->ApplyLinearImpulse(b2Vec2(0, -350), player->myRect->GetWorldCenter(), true);
					}
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				//newObject->addRectangle(event.button.x, event.button.y, 20, 20, true);
				break;

			}
		}
		
		//player->displayIt();
		player->displayIt2();
		//newObject->displayIt();
		newWindow->world->Step(1.0 / 30.0, 8, 3);      //update
		//SDL_UpdateWindowSurface(newWindow->window);
		if (1000.0 / 30.0 > SDL_GetTicks() - start)
		{
			SDL_Delay(1000.0 / 30.0 - (SDL_GetTicks() - start));
		}
		
		player->upateAnimation(player->myRect->GetPosition());
		//SDL_RenderClear(newWindow->renderTarget);
		//SDL_RenderPresent(newWindow->renderTarget);
	}

	SDL_Quit();

	return 0;
}

/*
	bool running = true;
	init();
	while(running)
	{
			start=SDL_GetTicks();
			while(SDL_PollEvent(&event))
			{
					switch(event.type)
					{
							case SDL_QUIT:
									running=false;
									break;
							case SDL_KEYDOWN:
									switch(event.key.keysym.sym)
									{
											case SDLK_ESCAPE:
													running=false;
													break;
									}
									break;
							case SDL_MOUSEBUTTONDOWN:
									addRectangle(event.button.x,event.button.y,20,20,true);
									break;

					}
			}
			display();
			world->Step(1.0/30.0,8,3);      //update
			SDL_UpdateWindowSurface(window);
			if (1000.0 / 30 > SDL_GetTicks() - start)
			{
				SDL_Delay(1000.0 / 30 - (SDL_GetTicks() - start));
			}

			frameTime++; //The following is more that I added
			if (FPS / frameTime == 4)
			{
				frameTime = 0;
				playerRect.x += frameWidth;
				if (playerRect.x >= textureWidth)
				{
					playerRect.x = 0;
				}
			}
			SDL_RenderClear(renderTarget);
			SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
			SDL_RenderPresent(renderTarget);
	}

	SDL_Quit();
	
	return 0;
}
*/
