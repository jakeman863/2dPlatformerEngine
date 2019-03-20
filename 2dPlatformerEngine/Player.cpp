#include "Player.h"

Player::Player(windowInstance* thisWindow)
{
	windowRef = thisWindow;
	myRect = addRectangle(100, 200, 50, 50, true);
	clone = new animationComponent("clone.png", 4, 2, 100, 200, 50, 50);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(3.0f);
}