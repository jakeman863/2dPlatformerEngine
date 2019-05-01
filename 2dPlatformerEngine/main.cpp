#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include "windowInstance.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void EnemyIdle(Enemy*);

int main(int argc, char *argv[])
{
	// Create World/Window
	windowInstance* newWindow = new windowInstance();
	
	// Instantiate an object
	GameObject* newObject = new GameObject(newWindow);
	Player* player = new Player(newWindow);
	
	string enemyCount = "0";
	string xPos;
	string yPos;
	string name = "Help";
	ifstream inFile;
	inFile.open("Level1List.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	getline(inFile, enemyCount);
	cout << enemyCount;
	int n = std::stoi(enemyCount);
	Enemy* en[5];
	int i = 0;
	while (i < n) {
		getline(inFile, name);
		getline(inFile, xPos);
		getline(inFile, yPos);
		en[i] = new Enemy(newWindow, stoi(xPos), stoi(yPos), name);
		en[i]->name = name;
		i++;
	}
	inFile.close();


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
					vel.x = 8;
					player->myRect->SetLinearVelocity(vel);
					break;
				case SDLK_a:
					vel.x = -8;
					player->myRect->SetLinearVelocity(vel);
					break;
				case SDLK_SPACE:
					if (vel.y == 0)
					{
						player->myRect->ApplyLinearImpulse(b2Vec2(0, -100), player->myRect->GetWorldCenter(), true);
					}
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				newObject->addRectangle(event.button.x, event.button.y, 20, 20, true);
				break;

			}
		}

		for (int i = 0; i < n; i++)
		{
			EnemyIdle(en[i]);
			b2Vec2 vel2 = en[0]->myRect->GetLinearVelocity();;
		}

		newObject->displayIt();
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

void EnemyIdle(Enemy* en)
{
	if (en->name.compare("[SLIME]") == 0)
	{
		if (en->counter >= 0 && en->counter < 20)
		{
			b2Vec2 vel2 = en->myRect->GetLinearVelocity();
			vel2.x = 4;
			en->myRect->SetLinearVelocity(vel2);
			en->counter++;
		}
		if (en->counter >=20 && en->counter < 40)
		{
			b2Vec2 vel2 = en->myRect->GetLinearVelocity();
			vel2.x = -4;
			en->myRect->SetLinearVelocity(vel2);
			en->counter++;
		}
		if (en->counter == 40)
		{
			b2Vec2 vel2 = en->myRect->GetLinearVelocity();
			vel2.x = 0;
			en->myRect->SetLinearVelocity(vel2);
			en->counter = 0;
		}
	}
	if (en->name.compare("[ELF]") == 0)
	{
		b2Vec2 vel2 = en->myRect->GetLinearVelocity();
		if (vel2.y == 0)
		{
			en->myRect->ApplyLinearImpulse(b2Vec2(0, -100), en->myRect->GetWorldCenter(), true);
		}
	}
}
