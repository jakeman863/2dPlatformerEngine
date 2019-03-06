#include "Player.h"

Player::Player(windowInstance* thisWindow)
{
	windowRef = thisWindow;
	myRect = addRectangle(100, 200, 50, 50, true);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(3.0f);
}

