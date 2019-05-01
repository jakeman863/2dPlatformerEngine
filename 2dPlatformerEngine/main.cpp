/*****************************************************
* Program File Name: main.cpp
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/17
* Purpose: Bring all components together
*
* Input: Object values, and map
*
* Output: Produce engine and eventually game
***************************************************************/

#include <Windows.h>
#include "Player.h"
#include "GameObject.h"
#include "windowInstance.h"
#include "ImportWorld.h"
#include "Utilities.h"

int main(int argc, char *argv[])
{	
	// Create World/Window
	windowInstance* newWindow = new windowInstance();
	
	// Instantiate an object
	GameObject * objectList[100];

	for (int i = 0; i < 100; i++)
	{
		objectList[i] = nullptr;
	}
	
	//Object creation
	objectList[0] = new GameObject(newWindow, 1, 640 / 2, 8500, 64000, 30, false);
	objectList[1] = new Player(newWindow, 51, "clone.png", 4, 2, 100, 200, 50, 50);
	objectList[2] = new GameObject(newWindow, 2, 0, 0, 0, 0, false);

	//Start
	Uint32 start;
	SDL_Event event;
	bool running = true;
	
	// Enable WinAPI event processing
	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);

	//Start objects
	for (int i = 0; i < 100; i++)
	{
		if (objectList[i] != nullptr)
		{
			objectList[i]->beginningOperation();
		}
	}

	//Main while loop
	while (running)
	{
		bool madeChange = false;
		bool doCheck = false;

		b2Vec2 vel = objectList[1]->myRect->GetLinearVelocity();;

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
							objectList[1]->myRect->SetLinearVelocity(vel);
							break;
						case SDLK_a:
							vel.x = -75;
							objectList[1]->myRect->SetLinearVelocity(vel);
							break;
						case SDLK_SPACE:
							if (vel.y == 0)
							{
								objectList[1]->myRect->ApplyLinearImpulse(b2Vec2(0, -350), objectList[1]->myRect->GetWorldCenter(), true);
							}
							break;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					//newObject->addRectangle(event.button.x, event.button.y, 20, 20, true);
					break;
				case SDL_SYSWMEVENT: // Check menubar event message
					OutputDebugString("Received SDL_SYSWMEVENT");
					if (event.syswm.msg->msg.win.msg == WM_COMMAND) {
						if (LOWORD(event.syswm.msg->msg.win.wParam) == ID_EXIT) { // Exit
							running = false;
						}
						else if (LOWORD(event.syswm.msg->msg.win.wParam) == ID_LEVELEDITOR) { // Open level editor
							STARTUPINFO si;
							PROCESS_INFORMATION pi;
							ZeroMemory(&si, sizeof(si));
							ZeroMemory(&pi, sizeof(pi));
							// Start Level Editor tool -> "..\\Maps\\world-edit-tool-setup-1.0.0.exe"
							int val = CreateProcess(TEXT(".\\Maps\\world-edit-tool\\Level Editor Tool.exe"),
								NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

						}
						else if (LOWORD(event.syswm.msg->msg.win.wParam) == ID_OBJECTEDITOR) {

							//Load current gameobjects
							for (int i = 0; i < 100; i++)
							{
								if (objectList[i] != nullptr && objectList[i]->objectID <= 50)
								{
									newWindow->loadGameObjectsIntoEditor(objectList[i]->objectID, objectList[i]->xVal, objectList[i]->yVal, objectList[i]->wVal, objectList[i]->hVal);
								}
								else if (objectList[i] != nullptr && objectList[i]->objectID > 50)
								{
									newWindow->loadPlayerIntoEditor(objectList[i]->objectID, objectList[i]->fName, objectList[i]->nWideVal, objectList[i]->nHighVal, objectList[i]->xVal, objectList[i]->yVal, objectList[i]->wVal, objectList[i]->hVal);
								}
							}

							//Open window
							newWindow->windowUpdate();
							doCheck = true;
						}
						else if (LOWORD(event.syswm.msg->msg.win.wParam) == ID_ABOUT) { // Open level editor
							//
						}
					}
					break;
			}
		}
		
		//Check for object changes (Currently isn't working, since Utilities is being destroyed after closure)
		if (doCheck == true)
		{
			doCheck = false;
			
			//Check for changes
			for (int i = 0; i < 100; i++)
			{
				if (objectList[i] != nullptr && objectList[i]->objectID <= 50)
				{
					objectList[i]->xVal = Utilities::objectNonStringVals[i][1];
					objectList[i]->yVal = Utilities::objectNonStringVals[i][2];
					objectList[i]->wVal = Utilities::objectNonStringVals[i][3];
					objectList[i]->hVal = Utilities::objectNonStringVals[i][4];
					cout << objectList[i]->objectID << " " << objectList[i]->xVal << " " << objectList[i]->yVal << " " << objectList[i]->wVal << " " << objectList[i]->hVal << endl;
					
					/*
					int x = objectList[i]->xVal;
					int y = objectList[i]->yVal;
					int w = objectList[i]->wVal;
					int h = objectList[i]->hVal;
					newWindow->changeGameObjectsInEditor(objectList[i]->objectID, x, y, w, h);
					objectList[i]->xVal = x;
					objectList[i]->yVal = y;
					objectList[i]->wVal = w;
					objectList[i]->hVal = h;
					*/
				}
				else if (objectList[i] != nullptr && objectList[i]->objectID > 50)
				{
					objectList[i]->xVal = Utilities::objectNonStringVals[i][1];
					objectList[i]->yVal = Utilities::objectNonStringVals[i][2];
					objectList[i]->wVal = Utilities::objectNonStringVals[i][3];
					objectList[i]->hVal = Utilities::objectNonStringVals[i][4];
					objectList[i]->nWideVal = Utilities::objectNonStringVals[i][5];
					objectList[i]->nHighVal = Utilities::objectNonStringVals[i][6];
					objectList[i]->fName = Utilities::objectFileName[i];
					cout << objectList[i]->objectID << " " << objectList[i]->fName << " " << objectList[i]->nWideVal << " " << objectList[i]->nHighVal << " " << objectList[i]->xVal << " " << objectList[i]->yVal << " " << objectList[i]->wVal << " " << objectList[i]->hVal << endl;
					
					/*
					string fN = objectList[i]->fName;
					int nW = objectList[i]->nWideVal;
					int nH = objectList[i]->nHighVal;
					int x = objectList[i]->xVal;
					int y = objectList[i]->yVal;
					int w = objectList[i]->wVal;
					int h = objectList[i]->hVal;
					newWindow->changePlayerInEditor(objectList[i]->objectID, fN, nW, nH, x, y, w, h);
					objectList[i]->fName = fN;
					objectList[i]->nWideVal = nW;
					objectList[i]->nHighVal = nH;
					objectList[i]->xVal = x;
					objectList[i]->yVal = y;
					objectList[i]->wVal = w;
					objectList[i]->hVal = h;
					cout << objectList[i]->objectID << " " << objectList[i]->fName << " " << objectList[i]->nWideVal << " " << objectList[i]->nHighVal << " " << objectList[i]->xVal << " " << objectList[i]->yVal << " " << objectList[i]->wVal << " " << objectList[i]->hVal << endl;
					*/
				}
			}
		}

		objectList[1]->displayIt();
		objectList[1]->displayIt2();
		newWindow->world->Step(1.0 / 30.0, 8, 3);      //update
		//SDL_UpdateWindowSurface(newWindow->window);
		if (1000.0 / 30.0 > SDL_GetTicks() - start)
		{
			SDL_Delay(1000.0 / 30.0 - (SDL_GetTicks() - start));
		}
		
		//player->updateAnimation(player->myRect->GetPosition());
		objectList[1]->updateAnimation(objectList[1]->myRect->GetPosition());
		//SDL_RenderClear(newWindow->renderTarget);
		//SDL_RenderPresent(newWindow->renderTarget);
	}

	SDL_Quit();
	return 0;
}