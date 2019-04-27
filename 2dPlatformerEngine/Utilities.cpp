#include "Utilities.h"

using namespace Utilities;

/*
 * Retrieve address and handle of SDL window and specific
 * subsystem used by SDL to create the window (OS).
 */
HWND Utilities::getSDLWinHandle(SDL_Window* win) {
	SDL_SysWMinfo infoWindow;
	SDL_VERSION(&infoWindow.version);
	if (!SDL_GetWindowWMInfo(win, &infoWindow)) {
		return NULL;
	}
	return (infoWindow.info.win.window);
}

/*
 * Initialize window drop down elements.
 */
void Utilities::ActivateMenu(HWND windowRef) {
	hMenuBar = CreateMenu();
	hFile = CreateMenu();
	hTools = CreateMenu();
	hHelp = CreateMenu();

	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, "File");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hTools, "Tools");
	AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hHelp, "Help");

	AppendMenu(hFile, MF_STRING, ID_EXIT, "Exit");

	AppendMenu(hTools, MF_STRING, ID_LEVELEDITOR, "Launch Level Editor");

	AppendMenu(hHelp, MF_STRING, ID_ABOUT, "About");

	SetMenu(windowRef, hMenuBar);
}