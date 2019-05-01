#include "Player.h"

Player::Player(windowInstance* thisWindow)
{
	windowRef = thisWindow;
	b2Color red(1, 0, 0);
	myRect = addRectangle(100, 200, 50, 50, true, red , PLAYER, BOUNDARY | HITBOX, false);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(3.0f);
}

