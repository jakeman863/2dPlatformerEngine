#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

Enemy::Enemy(windowInstance* thisWindow, int xPos, int yPos, string name)
{
	windowRef = thisWindow;
	ifstream inFile2;
	string width;
	string height;
	inFile2.open("EnemyList.txt");
	if (!inFile2) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	b2Color green(0, 1, 0);
	string currentName = "";
	while (currentName.compare(name) != 0)
	{
		getline(inFile2, currentName);
		if (currentName.compare(name) == 0)
			cout << xPos << " " << yPos << " " << currentName << endl;
	}
	getline(inFile2, width);
	getline(inFile2, height);
	myRect = addRectangle(xPos, yPos, stoi(width), stoi(height), true, green, ENEMY, BOUNDARY, false);
	myRect->SetFixedRotation(true);
	myRect->SetGravityScale(3.0f);
	inFile2.close();
}

