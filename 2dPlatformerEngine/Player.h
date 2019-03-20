#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"
#include "animationComponent.h"

class Player: public GameObject
{
	private:

	public:
		animationComponent* clone;
		Player(windowInstance* thisWindow);
};
#endif