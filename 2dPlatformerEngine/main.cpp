#include "Player.h"
#include "GameObject.h"
#include "windowInstance.h"


int main(int argc, char *argv[])
{
	// Create World/Window
	windowInstance* newWindow = new windowInstance();
	// Instantiate an object
	GameObject* newObject = new GameObject(*newWindow);

	Uint32 start;
	SDL_Event event;
	bool running = true;
	while (running)
	{
		b2Vec2 vel;
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
					vel.x = 10;

					//testPlayer.myRect->SetLinearVelocity(vel);
					break;
				case SDLK_a:
					vel.x = -10;

					//testPlayer.myRect->SetLinearVelocity(vel);
					break;
				case SDLK_SPACE:
					//player->SetLinearVelocity(b2Vec2(vel.x, 0));

					//player->ApplyForce(b2Vec2(0, -1500), player->GetWorldCenter(), true);
					if (vel.y == 0)
					{
						//testPlayer.myRect->ApplyLinearImpulse(b2Vec2(0, -100), testPlayer.myRect->GetWorldCenter(), true);
					}
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				//testPlayer.addRectangle(event.button.x, event.button.y, 20, 20, true);
				break;

			}
		}
		//testPlayer.displayIt();
		newWindow->world->Step(1.0 / 30.0, 8, 3);      //update
		SDL_UpdateWindowSurface(newWindow->window);
		if (1000.0 / 30.0 > SDL_GetTicks() - start)
		{
			SDL_Delay(1000.0 / 30.0 - (SDL_GetTicks() - start));
		}
	}

	SDL_Quit();


	return 0;
}

