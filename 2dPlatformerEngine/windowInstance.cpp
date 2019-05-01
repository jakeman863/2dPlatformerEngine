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

#include "windowInstance.h"
#include "Utilities.h"

HWND windowHandler;

/************************************************************************************************************
* sets the private variables to there default values
*
* parameters: there are no parameters in this constructor
*
* return: nothing is returned in this constructor
************************************************************************************************************/
windowInstance::windowInstance()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_VIDEO);

	renderTarget = nullptr;
	window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	screen = SDL_GetWindowSurface(window);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	windowHandler = Utilities::getSDLWinHandle(window);
	Utilities::ActivateMenu(windowHandler);
	cameraRect = {0, 0, 640, 480};
	world = new b2World(b2Vec2(0.0f, 9.81f));
}

/************************************************************************************************************
* Deactivate
*
* parameters: there are no parameters
*
* return: nothing is returned 
************************************************************************************************************/
windowInstance::~windowInstance()
{
}

/************************************************************************************************************
* Open the object editor
*
* parameters: there are no parameters
*
* return: nothing is returned
************************************************************************************************************/
void windowInstance :: windowUpdate()
{
	Utilities::openObjectEditor();
}

/************************************************************************************************************
* Load gameobjects
*
* parameters: object characteristics
*
* return: nothing is returned
************************************************************************************************************/
void windowInstance::loadGameObjectsIntoEditor(int oID, int x, int y, int w, int h)
{
	Utilities::bringInGameObjectDetails(oID, x, y, w, h);
}

/************************************************************************************************************
* Load player
*
* parameters: player characteristics
*
* return: nothing is returned
************************************************************************************************************/
void windowInstance::loadPlayerIntoEditor(int oID, string fileName, int numWide, int numHigh, int x, int y, int w, int h)
{
	Utilities::bringInPlayerDetails(oID, fileName, numWide, numHigh, x, y, w, h);
}

/************************************************************************************************************
* Change gameobject
*
* parameters: gameobjects characteristics
*
* return: nothing is returned
************************************************************************************************************/
void windowInstance::changeGameObjectsInEditor(int oID, int &x, int &y, int &w, int &h)
{
	x = Utilities::changeX(oID);
	y = Utilities::changeY(oID);
	w = Utilities::changeW(oID);
	h = Utilities::changeH(oID);
}

/************************************************************************************************************
* Change player
*
* parameters: player characteristics
*
* return: nothing is returned
************************************************************************************************************/
void windowInstance::changePlayerInEditor(int oID, string &fileName, int &numWide, int &numHigh, int &x, int &y, int &w, int &h)
{
	fileName = Utilities::changeFN(oID);
	numWide = Utilities::changeNW(oID);
	numHigh = Utilities::changeNH(oID);
	x = Utilities::changeX(oID);
	y = Utilities::changeY(oID);
	w = Utilities::changeW(oID);
	h = Utilities::changeH(oID);
}
