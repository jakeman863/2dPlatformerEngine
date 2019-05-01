#ifndef WINDOWINSTANCE_H
#define WINDOWINSTANCE_H

/*****************************************************
* Program File Name: windowInstance.h
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/17
* Purpose: Create a working window
*
* Input: Concerning character editor, game object characteristics
*
* Output: Window
***************************************************************/

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Box2D/Box2D.h"
#include "windowInstance.h"
#include <string>
using namespace std;

//Class
class windowInstance
{
	//Public attributes
	public:
		const int WIDTH = 1280;
		const int HEIGHT = 960;
		b2World* world;
		SDL_Surface* screen;
		SDL_Window* window;
		SDL_Renderer *renderTarget;
		SDL_Rect cameraRect;

		windowInstance();
		~windowInstance();
		void windowUpdate();
		void loadGameObjectsIntoEditor(int oID, int x, int y, int w, int h);
		void loadPlayerIntoEditor(int oID, string fileName, int numWide, int numHigh, int x, int y, int w, int h);
		void changeGameObjectsInEditor(int oID, int &x, int &y, int &w, int &h);
		void changePlayerInEditor(int oID, string &fileName, int &numWide, int &numHigh, int &x, int &y, int &w, int &h);
};
#endif
