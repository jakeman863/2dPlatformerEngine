#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"
#include "AnimationComponent.h"

using namespace std;

class Player : public GameObject
{
	private:

	public:
		AnimationComponent *clone;
		Player(windowInstance* thisWindow);
		void upateAnimation(b2Vec2 currentPlayerPosition);
};
#endif