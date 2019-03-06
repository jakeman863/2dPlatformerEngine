#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"

class Player: public GameObject
{
	private:

	public:
		Player(windowInstance* thisWindow);
};
#endif