#include "EnemyHitbox.h"

EnemyHitbox::EnemyHitbox(windowInstance* thisWindow)
{
	windowRef = thisWindow;
	b2Color green(0, 1, 0);
	myRect = addRectangle(200, 200, 70, 70, true, green, ENEMY, BOUNDARY, true);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(3.0f);
}
