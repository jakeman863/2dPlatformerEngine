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
	HWND getSDLWinHandle(SDL_Window*);

	/*
	 * Initialize window drop down elements.
	 */
	void ActivateMenu(HWND);
}