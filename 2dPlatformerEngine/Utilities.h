#pragma once

/*****************************************************
* Program File Name: windowInstance.h
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/17
* Purpose: Create menu bar and object editor
*
* Input: Mainly game object characteristics, and current window
*
* Output: GUI components
***************************************************************/

#include <Windows.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include "GameObject.h"
#include "Player.h"
#include <cstring>
#include <string>
#include <iostream>

//Namespace
namespace Utilities {
	
	// Globals
	#define ID_LEVELEDITOR 1
	#define ID_ABOUT 2
	#define ID_EXIT 3
	#define ID_CONTROLS 4
	#define ID_SAVE 5
	#define ID_OPEN 6
	#define ID_OBJECTEDITOR 7
	#define FILE_MENU_EXIT 8
	#define HELP_MENU_ABOUT 9
	#define SHOW_GAMEOBJECT_CHARACTERISTICS 10
	#define SHOW_PLAYER_CHARACTERISTICS 11
	#define SHOW_ACTUAL_PLAYER 12
	#define SHOW_ACTUAL_GAMEOBJECT 13
	#define CHANGE_ACTUAL_PLAYER 14
	#define CHANGE_ACTUAL_GAMEOBJECT 15

	// Static variables
	static HMENU hHelp;
	static HMENU hTools;
	static HMENU hFile;
	static HMENU hMenuBar;
	static int spotR = 0;
	static int objectNonStringVals[100][8];
	static string objectFileName[100];
	static HWND hGOEditX, hGOEditY, hGOEditW, hGOEditH, hGOEditV, hGOEditAF, hGOEditANW, hGOEditANH, hGOEditAX, hGOEditAY, hGOEditAW, hGOEditAH;
	static HWND hPEditX, hPEditY, hPEditW, hPEditH, hPEditV, hPEditAF, hPEditANW, hPEditANH, hPEditAX, hPEditAY, hPEditAW, hPEditAH;
	static HMENU hMenu;

	//Function prototypes
	HWND getSDLWinHandle(SDL_Window* win);
	void ActivateMenu(HWND windowRef);
	void AddOEMenus(HWND hWnd);
	void AddObjectButtons(HWND hWnd);
	void ShowGameObjectCharacteristics(HWND hWnd);
	void ShowPlayerCharacteristics(HWND hWnd);
	void ShowGameObject(HWND hWnd);
	void ShowPlayer(HWND hWnd);
	void ChangeGameObject(HWND hWnd, wchar_t hGOEditXT[], wchar_t hGOEditYT[], wchar_t hGOEditWT[], wchar_t hGOEditHT[], wchar_t hGOEditVT[], wchar_t hGOEditAFT[], wchar_t hGOEditANWT[100], wchar_t hGOEditANHT[], wchar_t hGOEditAXT[], wchar_t hGOEditAYT[], wchar_t hGOEditAWT[], wchar_t hGOEditAHT[]);
	void ChangePlayer(HWND hWnd, wchar_t hPEditXT[], wchar_t hPEditYT[], wchar_t hPEditWT[], wchar_t hPEditHT[], wchar_t hPEditVT[], wchar_t hPEditAFT[], wchar_t hPEditANWT[100], wchar_t hPEditANHT[], wchar_t hPEditAXT[], wchar_t hPEditAYT[], wchar_t hPEditAWT[], wchar_t hPEditAHT[]);
	void showChanges(HWND hWnd);
	LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	int WINAPI ObjectEditorWindow(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow);
	void openObjectEditor();
	void bringInGameObjectDetails(int oID, int x, int y, int w, int h);
	void bringInPlayerDetails(int oID, string fileName, int numWide, int numHigh, int x, int y, int w, int h);
	int changeX(int oID);
	int changeY(int oID);
	int changeW(int oID);
	int changeH(int oID);
	int changeNW(int oID);
	int changeNH(int oID);
	string changeFN(int oID);
}