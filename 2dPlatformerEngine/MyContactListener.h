#include "Box2D/Box2D.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"

bool getRadarAndAircraft(b2Contact* contact, Enemy*& radarEntity, Player*& aircraftEntity)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	//make sure only one of the fixtures was a sensor
	bool sensorA = fixtureA->IsSensor();
	bool sensorB = fixtureB->IsSensor();
	//if (!(sensorA ^ sensorB))
		//return false;

	Enemy* entityA = static_cast<Enemy*>(fixtureA->GetBody()->GetUserData());
	Player* entityB = static_cast<Player*>(fixtureB->GetBody()->GetUserData());

	if (sensorA) { //fixtureB must be an enemy aircraft
		Enemy* entityA = static_cast<Enemy*>(fixtureA->GetBody()->GetUserData());
		Player* entityB = static_cast<Player*>(fixtureB->GetBody()->GetUserData());
	}
	else { //fixtureA must be an enemy aircraft
		Enemy* entityA = static_cast<Enemy*>(fixtureB->GetBody()->GetUserData());
		Player* entityB = static_cast<Player*>(fixtureA->GetBody()->GetUserData());
	}
	return true;
}

class MyContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact) {
		Enemy* radarEntity;
		Player* aircraftEntity;
		if (getRadarAndAircraft(contact, radarEntity, aircraftEntity))
			radarEntity->radarAcquiredEnemy();
	}

	void EndContact(b2Contact* contact) {
		Enemy* radarEntity;
		Player* aircraftEntity;
		if (getRadarAndAircraft(contact, radarEntity, aircraftEntity))
			radarEntity->radarLostEnemy();
	}
};