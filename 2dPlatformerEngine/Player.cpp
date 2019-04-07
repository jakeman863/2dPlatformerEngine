#include "Player.h"

Player::Player(windowInstance* thisWindow)
{
	windowRef = thisWindow;
	clone = new AnimationComponent("clone.png", 4, 2, 100, 200, 50, 50);
	myRect = addRectangle(100, 200, 50, 50, true);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(3.0f);
}

void Player::upateAnimation(b2Vec2 currentPlayerPosition)
{
	clone->increaseFrameTime();
	clone->checkFrameTime(currentPlayerPosition.x, currentPlayerPosition.y);
}

/*
100, 200, 50, 50,
*/