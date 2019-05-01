#ifndef ENEMY_HIT_H
#define ENEMY_HIT_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"

class EnemyHitbox : public GameObject
{
private:

public:
	EnemyHitbox(windowInstance* thisWindow);
};
#endif#pragma once
