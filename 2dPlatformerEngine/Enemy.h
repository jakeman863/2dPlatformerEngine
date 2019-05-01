#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <SDL.h>
#include "Box2D/Box2D.h"
#include "GameObject.h"

class Enemy : public GameObject
{
private:
	
public:
	Enemy(windowInstance* thisWindow, int xPos, int yPos, std::string EnemyName);
	std::string name = "";
	int counter = 0;
	void resetCounter();
};
#endif