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

#include "Utilities.h"

using namespace Utilities;

/************************************************************************************************************
* Retrieve address and handle of SDL window and specific
* subsystem used by SDL to create the window (OS).
*
* parameters: SDL Window
*
* return: Win32 GUI components
************************************************************************************************************/
HWND Utilities::getSDLWinHandle(SDL_Window* win) {
	//Find and return current window
	SDL_SysWMinfo infoWindow;
	SDL_VERSION(&infoWindow.version);
	if (!SDL_GetWindowWMInfo(win, &infoWindow)) {
		return NULL;
	}
	return (infoWindow.info.win.window);
}

/************************************************************************************************************
* Initializes window drop down elements
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ActivateMenu(HWND windowRef) {
	hMenuBar = CreateMenu();
	hFile = CreateMenu();
	hTools = CreateMenu();
	hHelp = CreateMenu();

	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, "File");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hTools, "Tools");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hHelp, "Help");

	AppendMenu(hFile, MF_STRING, ID_SAVE, "Save");
	AppendMenu(hFile, MF_STRING, ID_OPEN, "Open");
	AppendMenu(hFile, MF_STRING, ID_EXIT, "Exit");

	AppendMenu(hTools, MF_STRING, ID_LEVELEDITOR, "Launch Level Editor");
	AppendMenu(hTools, MF_STRING, ID_OBJECTEDITOR, "Launch Object Editor");

	AppendMenu(hHelp, MF_STRING, ID_ABOUT, "About");

	SetMenu(windowRef, hMenuBar);
}

/************************************************************************************************************
* Initializes object editor drop down elements
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::AddOEMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hHelpMenu = CreateMenu();

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");

	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");
	AppendMenu(hHelpMenu, MF_STRING, HELP_MENU_ABOUT, "About Module");

	SetMenu(hWnd, hMenu);
}

/************************************************************************************************************
* Adds gameobject buttons
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::AddObjectButtons(HWND hWnd)
{
	int yHelper = 25;
	int j = 1;
	int k = 1;

	//For loop creating buttons for each gameobject
	for (int i = 0; i < spotR; i++)
	{
		if (objectNonStringVals[i][0] > 50)
		{
			CreateWindowW(L"Button", L"Player", WS_VISIBLE | WS_CHILD, 25, 25 + yHelper, 90, 25, hWnd, (HMENU)SHOW_PLAYER_CHARACTERISTICS, NULL, NULL);
			objectNonStringVals[i][7] = j;
			yHelper += 25;
			j++;
		}
		else if (objectNonStringVals[i][0] <= 50)
		{
			CreateWindowW(L"Button", L"GameObject", WS_VISIBLE | WS_CHILD, 25, 25 + yHelper, 90, 25, hWnd, (HMENU)SHOW_GAMEOBJECT_CHARACTERISTICS, NULL, NULL);
			objectNonStringVals[i][7] = k;
			yHelper += 25;
			k++;
		}
	}
}

/************************************************************************************************************
* Creates static and edit controls for all gameobjects
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ShowGameObjectCharacteristics(HWND hWnd)
{
	CreateWindowW(L"Static", L"GO - X", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 25, 100, 25, hWnd, NULL, NULL, NULL);
	hGOEditX = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 50, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Y", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 75, 100, 25, hWnd, NULL, NULL, NULL);
	hGOEditY = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 100, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Width", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 125, 100, 25, hWnd, NULL, NULL, NULL);
	hGOEditW = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 150, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Height", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 175, 100, 25, hWnd, NULL, NULL, NULL);
	hGOEditH = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 200, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Velocity", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 225, 100, 25, hWnd, NULL, NULL, NULL);
	hGOEditV = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 250, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. File", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 25, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditAF = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 50, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. Num Wide", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 75, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditANW = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 100, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. Num High", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 125, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditANH = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 150, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. X", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 175, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditAX = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 200, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. Y", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 225, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditAY = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 250, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. Width", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 275, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditAW = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 300, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"GO - Anim. Height", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 325, 175, 25, hWnd, NULL, NULL, NULL);
	hGOEditAH = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 350, 175, 25, hWnd, NULL, NULL, NULL);

	//Buttons to show current object values or confirm changes
	CreateWindowW(L"Button", L"Confirm GameObject Changes", WS_VISIBLE | WS_CHILD, 50, 400, 200, 25, hWnd, (HMENU)CHANGE_ACTUAL_GAMEOBJECT, NULL, NULL);
	CreateWindowW(L"Button", L"Show GameObject Current Values", WS_VISIBLE | WS_CHILD, 255, 400, 250, 25, hWnd, (HMENU)SHOW_ACTUAL_GAMEOBJECT, NULL, NULL);
}

/************************************************************************************************************
* Creates static and edit controls for all players
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ShowPlayerCharacteristics(HWND hWnd)
{
	CreateWindowW(L"Static", L"P - X", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 25, 100, 25, hWnd, NULL, NULL, NULL);
	hPEditX = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 50, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Y", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 75, 100, 25, hWnd, NULL, NULL, NULL);
	hPEditY = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 100, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Width", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 125, 100, 25, hWnd, NULL, NULL, NULL);
	hPEditW = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 150, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Height", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 175, 100, 25, hWnd, NULL, NULL, NULL);
	hPEditH = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 200, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Velocity", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 150, 225, 100, 25, hWnd, NULL, NULL, NULL);
	hPEditV = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 150, 250, 100, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. File", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 25, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditAF = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 50, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. Num Wide", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 75, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditANW = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 100, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. Num High", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 125, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditANH = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 150, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. X", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 175, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditAX = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 200, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. Y", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 225, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditAY = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 250, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. Width", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 275, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditAW = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 300, 175, 25, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"P - Anim. Height", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 250, 325, 175, 25, hWnd, NULL, NULL, NULL);
	hPEditAH = CreateWindowW(L"Edit", L"...", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 250, 350, 175, 25, hWnd, NULL, NULL, NULL);

	//Buttons to confirm changes, or show current values
	CreateWindowW(L"Button", L"Confirm Player Changes", WS_VISIBLE | WS_CHILD, 50, 375, 200, 25, hWnd, (HMENU)CHANGE_ACTUAL_PLAYER, NULL, NULL);
	CreateWindowW(L"Button", L"Show Player Current Values", WS_VISIBLE | WS_CHILD, 255, 375, 200, 25, hWnd, (HMENU)SHOW_ACTUAL_PLAYER, NULL, NULL);
}

/************************************************************************************************************
* Show object values
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ShowGameObject(HWND hWnd)
{
	static int alreadySeen = -1;
	int spot = 0;

	//Find object
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] <= 50 && i != alreadySeen)
		{
			spot = i;
			alreadySeen = i;
			break;
		}
	}

	//Display
	char buff[300];
	string ID = "Object ID: " + to_string(objectNonStringVals[spot][0]);
	string X = "X Value: " + to_string(objectNonStringVals[spot][1]);
	string Y = "Y Value: " + to_string(objectNonStringVals[spot][2]);
	string W = "Width Value: " + to_string(objectNonStringVals[spot][3]);
	string H = "Height Value: " + to_string(objectNonStringVals[spot][4]);
	string fileName = "File Name: " + objectFileName[spot];
	string animNumWide = "Number Wide: " + to_string(objectNonStringVals[spot][5]);
	string animNumHigh = "Number High: " + to_string(objectNonStringVals[spot][6]);
	string values = ID + "\n" + X + "\n" + Y + "\n" + W + "\n" + H + "\n" + fileName + "\n" + animNumWide + "\n" + animNumHigh;
	sprintf_s(buff, "Object Values:\n%s", values.c_str());
	MessageBox(hWnd, buff, "Current Player Characteristics", MB_OK);
}

/************************************************************************************************************
* Show player values
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ShowPlayer(HWND hWnd)
{
	int spot = 0;
	static int alreadySeen = -1;

	//Find player
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] > 50 && i != alreadySeen)
		{
			spot = i;
			alreadySeen = i;
			break;
		}
	}

	//Display changes
	char buff[300];
	string ID = "Object ID: " + to_string(objectNonStringVals[spot][0]);
	string X = "X Value: " + to_string(objectNonStringVals[spot][1]);
	string Y = "Y Value: " + to_string(objectNonStringVals[spot][2]);
	string W = "Width Value: " + to_string(objectNonStringVals[spot][3]);
	string H = "Height Value: " + to_string(objectNonStringVals[spot][4]);
	string fileName = "File Name: " + objectFileName[spot];
	string animNumWide = "Number Wide: " + to_string(objectNonStringVals[spot][5]);
	string animNumHigh = "Number High: " + to_string(objectNonStringVals[spot][6]);
	string values = ID + "\n" + X + "\n" + Y + "\n" + W + "\n" + H + "\n" + fileName + "\n" + animNumWide + "\n" + animNumHigh;
	sprintf_s(buff, "Object Values:\n%s", values.c_str());
	MessageBox(hWnd, buff, "Current Player Characteristics", MB_OK);
}

/************************************************************************************************************
* Change the gameobject
*
* parameters: edit control inputs
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ChangeGameObject(HWND hWnd, wchar_t hGOEditXT[], wchar_t hGOEditYT[], wchar_t hGOEditWT[], wchar_t hGOEditHT[], wchar_t hGOEditVT[], wchar_t hGOEditAFT[], wchar_t hGOEditANWT[100], wchar_t hGOEditANHT[], wchar_t hGOEditAXT[], wchar_t hGOEditAYT[], wchar_t hGOEditAWT[], wchar_t hGOEditAHT[])
{
	static int alreadySeen = -1;
	int spot = 0;
	wstring ws(hGOEditAFT);

	//Find object
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] <= 50 && i != alreadySeen)
		{
			spot = i;
			alreadySeen = i;
			break;
		}
	}

	//Conduct change
	if (_wtoi(hGOEditXT) != 0 && _wtoi(hGOEditYT) != 0 && _wtoi(hGOEditWT) != 0 && _wtoi(hGOEditHT) != 0 && _wtoi(hGOEditANWT) != 0 && _wtoi(hGOEditANHT) != 0)
	{
		objectNonStringVals[spot][1] = _wtoi(hGOEditXT);
		objectNonStringVals[spot][2] = _wtoi(hGOEditYT);
		objectNonStringVals[spot][3] = _wtoi(hGOEditWT);
		objectNonStringVals[spot][4] = _wtoi(hGOEditHT);
		string fn(ws.begin(), ws.end());
		objectFileName[spot] = fn;
		objectNonStringVals[spot][5] = _wtoi(hGOEditANWT);
		objectNonStringVals[spot][6] = _wtoi(hGOEditANHT);
	}
}

/************************************************************************************************************
* Change player based
*
* parameters: edit control inputs
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::ChangePlayer(HWND hWnd, wchar_t hPEditXT[], wchar_t hPEditYT[], wchar_t hPEditWT[], wchar_t hPEditHT[], wchar_t hPEditVT[], wchar_t hPEditAFT[], wchar_t hPEditANWT[100], wchar_t hPEditANHT[], wchar_t hPEditAXT[], wchar_t hPEditAYT[], wchar_t hPEditAWT[], wchar_t hPEditAHT[])
{
	int spot = 0;
	static int alreadySeen = -1;
	wstring ws(hPEditAFT);

	//Find player
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] > 50 && i != alreadySeen)
		{
			spot = i;
			alreadySeen = i;
			break;
		}
	}

	//Conduct change
	if (_wtoi(hPEditXT) != 0 && _wtoi(hPEditYT) != 0 && _wtoi(hPEditWT) != 0 && _wtoi(hPEditHT) != 0 && _wtoi(hPEditANWT) != 0 && _wtoi(hPEditANHT) != 0)
	{
		objectNonStringVals[spot][1] = _wtoi(hPEditXT);
		objectNonStringVals[spot][2] = _wtoi(hPEditYT);
		objectNonStringVals[spot][3] = _wtoi(hPEditWT);
		objectNonStringVals[spot][4] = _wtoi(hPEditHT);
		string fn(ws.begin(), ws.end());
		objectFileName[spot] = fn;
		objectNonStringVals[spot][5] = _wtoi(hPEditANWT);
		objectNonStringVals[spot][6] = _wtoi(hPEditANHT);
	}
}

/************************************************************************************************************
* Show object changes
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::showChanges(HWND hWnd)
{
	//For loop showing all changes to gameobjects and player
	for (int i = 0; i < 100; i++)
	{
		string ID = "Object ID: " + to_string(objectNonStringVals[i][0]);
		string X = "X Value: " + to_string(objectNonStringVals[i][1]);
		string Y = "Y Value: " + to_string(objectNonStringVals[i][2]);
		string W = "Width Value: " + to_string(objectNonStringVals[i][3]);
		string H = "Height Value: " + to_string(objectNonStringVals[i][4]);
		string fileName = "File Name: " + objectFileName[i];
		string animNumWide = "Number Wide: " + to_string(objectNonStringVals[i][5]);
		string animNumHigh = "Number High: " + to_string(objectNonStringVals[i][6]);
		string values = ID + "\n" + X + "\n" + Y + "\n" + W + "\n" + H + "\n" + fileName + "\n" + animNumWide + "\n" + animNumHigh;
		
		if (objectNonStringVals[i][0] > 50)
		{
			cout << "Player" << endl << values << endl;
		}
		else if (objectNonStringVals[i][0] <= 50 && objectNonStringVals[i][0] != 0)
		{
			cout << "GameObject" << endl << values << endl;
		}
	}
}

/************************************************************************************************************
* Handles window actiosn
*
* parameters: win32 windowm msg, and other paramters
*
* return: action result is returned
************************************************************************************************************/
LRESULT CALLBACK Utilities::WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//Switch managing each change
	switch (msg)
	{
		case WM_COMMAND:
			switch (wp)
			{
			case FILE_MENU_EXIT:
				DestroyWindow(hWnd);
				break;
			case HELP_MENU_ABOUT:
				MessageBoxW(hWnd, L"The objective of this module is to modify in-game components.\nBelow should be the hierarchy of objects that you can edit. Once the desired object to be changed is chosen, its attributes will be displayed so that you can change them if you choose.", L"About This Module", MB_OK);
				break;
			case SHOW_PLAYER_CHARACTERISTICS:
				ShowPlayerCharacteristics(hWnd);
				break;
			case SHOW_GAMEOBJECT_CHARACTERISTICS:
				ShowGameObjectCharacteristics(hWnd);
				break;
			case SHOW_ACTUAL_PLAYER:
				ShowPlayer(hWnd);
				break;
			case SHOW_ACTUAL_GAMEOBJECT:
				ShowGameObject(hWnd);
				break;
			case CHANGE_ACTUAL_PLAYER:
				//Change window object values
				wchar_t hPEditXText[100];
				wchar_t hPEditYText[100];
				wchar_t hPEditWText[100];
				wchar_t hPEditHText[100];
				wchar_t hPEditVText[100];
				wchar_t hPEditAFText[100];
				wchar_t hPEditANWText[100];
				wchar_t hPEditANHText[100];
				wchar_t hPEditAXText[100];
				wchar_t hPEditAYText[100];
				wchar_t hPEditAWText[100];
				wchar_t hPEditAHText[100];
				GetWindowTextW(hPEditX, hPEditXText, 100);
				GetWindowTextW(hPEditY, hPEditYText, 100);
				GetWindowTextW(hPEditW, hPEditWText, 100);
				GetWindowTextW(hPEditH, hPEditHText, 100);
				GetWindowTextW(hPEditV, hPEditVText, 100);
				GetWindowTextW(hPEditAF, hPEditAFText, 100);
				GetWindowTextW(hPEditANW, hPEditANWText, 100);
				GetWindowTextW(hPEditANH, hPEditANHText, 100);
				GetWindowTextW(hPEditAX, hPEditAXText, 100);
				GetWindowTextW(hPEditAY, hPEditAYText, 100);
				GetWindowTextW(hPEditAW, hPEditAWText, 100);
				GetWindowTextW(hPEditAH, hPEditAHText, 100);
				ChangePlayer(hWnd, hPEditXText, hPEditYText, hPEditWText, hPEditHText, hPEditVText, hPEditAFText, hPEditANWText, hPEditANHText, hPEditAXText, hPEditAYText, hPEditAWText, hPEditAHText);
				break;
			case CHANGE_ACTUAL_GAMEOBJECT:
				//Change window object values
				wchar_t hGOEditXText[100];
				wchar_t hGOEditYText[100];
				wchar_t hGOEditWText[100];
				wchar_t hGOEditHText[100];
				wchar_t hGOEditVText[100];
				wchar_t hGOEditAFText[100];
				wchar_t hGOEditANWText[100];
				wchar_t hGOEditANHText[100];
				wchar_t hGOEditAXText[100];
				wchar_t hGOEditAYText[100];
				wchar_t hGOEditAWText[100];
				wchar_t hGOEditAHText[100];
				GetWindowTextW(hGOEditX, hGOEditXText, 100);
				GetWindowTextW(hGOEditY, hGOEditYText, 100);
				GetWindowTextW(hGOEditW, hGOEditWText, 100);
				GetWindowTextW(hGOEditV, hGOEditVText, 100);
				GetWindowTextW(hGOEditAF, hGOEditAFText, 100);
				GetWindowTextW(hGOEditANW, hGOEditANWText, 100);
				GetWindowTextW(hGOEditANH, hGOEditANHText, 100);
				GetWindowTextW(hGOEditAX, hGOEditAXText, 100);
				GetWindowTextW(hGOEditAY, hGOEditAYText, 100);
				GetWindowTextW(hGOEditAW, hGOEditAWText, 100);
				GetWindowTextW(hGOEditAH, hGOEditAHText, 100);
				ChangeGameObject(hWnd, hGOEditXText, hGOEditYText, hGOEditWText, hGOEditHText, hGOEditVText, hGOEditAFText, hGOEditANWText, hGOEditANHText, hGOEditAXText, hGOEditAYText, hGOEditAWText, hGOEditAHText);
				break;
			}
			break;
		case WM_CREATE:
			AddOEMenus(hWnd);
			AddObjectButtons(hWnd);
			break;
		case WM_DESTROY:
			showChanges(hWnd);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

/************************************************************************************************************
* Create object editor window
*
* parameters: window paramters
*
* return: integer, but more specifically the newly created window
************************************************************************************************************/
int WINAPI Utilities::ObjectEditorWindow(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = { 0 };
	
	//Setup window basics
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if (!RegisterClassW(&wc))
	{
		return -1;
	}

	//Create window
	CreateWindowW(L"myWindowClass", L"Object Editor", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//Setup default values
	for (int r = 0; r < 100; r++)
	{
		for (int c = 0; c < 7; c++)
		{
			objectNonStringVals[r][c] = 0;
		}
		objectFileName[r] = "";
	}

	return 0;
}

/************************************************************************************************************
* Opens our new window
*
* parameters: nothing
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::openObjectEditor()
{
	HINSTANCE hI = NULL;
	ObjectEditorWindow(hI, NULL, NULL, NULL);
}

/************************************************************************************************************
* Initializes gameobject list row 
*
* parameters: object ID, x, y, w, and h
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::bringInGameObjectDetails(int oID, int x, int y, int w, int h)
{
	objectNonStringVals[spotR][0] = oID;
	objectNonStringVals[spotR][1] = x;
	objectNonStringVals[spotR][2] = y;
	objectNonStringVals[spotR][3] = w;
	objectNonStringVals[spotR][4] = h;
	spotR++;
}

/************************************************************************************************************
* Initializes player object list row
*
* parameters: win32 window
*
* return: nothing is returned
************************************************************************************************************/
void Utilities::bringInPlayerDetails(int oID, string fileName, int numWide, int numHigh, int x, int y, int w, int h)
{
	//objects[spot] = new Player(nullptr, oID, fileName, numWide, numHigh, x, y, w, h);
	objectNonStringVals[spotR][0] = oID;
	objectNonStringVals[spotR][1] = x;
	objectNonStringVals[spotR][2] = y;
	objectNonStringVals[spotR][3] = w;
	objectNonStringVals[spotR][4] = h;
	objectNonStringVals[spotR][5] = numWide;
	objectNonStringVals[spotR][6] = numHigh;
	objectFileName[spotR] = fileName;
	spotR++;
}

/************************************************************************************************************
* Return changed x
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
int Utilities::changeX(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectNonStringVals[spot][1];
}

/************************************************************************************************************
* Return changed y
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
int Utilities::changeY(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectNonStringVals[spot][2];
}

/************************************************************************************************************
* Return changed w
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
int Utilities::changeW(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectNonStringVals[spot][3];
}

/************************************************************************************************************
* Return changed h
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
int Utilities::changeH(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectNonStringVals[spot][4];
}

/************************************************************************************************************
* Return changed number wide
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
int Utilities::changeNW(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectNonStringVals[spot][5];
}

/************************************************************************************************************
* Return changed number high
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
int Utilities::changeNH(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectNonStringVals[spot][6];
}

/************************************************************************************************************
* Return changed file name
*
* parameters: object ID
*
* return: characteristic value
************************************************************************************************************/
string Utilities::changeFN(int oID)
{
	int spot = 0;
	for (int i = 0; i < 100; i++)
	{
		if (objectNonStringVals[i][0] == oID)
		{
			spot = i;
		}
	}

	return objectFileName[spot];
}