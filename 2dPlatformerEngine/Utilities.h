#pragma once

#include <Windows.h>
#include <SDL.h>
#include <SDL_syswm.h>

namespace Utilities {

	// Globals
	#define ID_LEVELEDITOR 1
	#define ID_ABOUT 2
	#define ID_EXIT 3
	#define ID_CONTROLS 4

	// Static
	static HMENU hHelp;
	static HMENU hTools;
	static HMENU hFile;
	static HMENU hMenuBar;

	/*
	 * Retrieve address and handle of SDL window and specific
	 * subsystem used by SDL to create the window (OS).
	 */
	HWND getSDLWinHandle(SDL_Window* win) {
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
	void ActivateMenu(HWND windowRef) {
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
}