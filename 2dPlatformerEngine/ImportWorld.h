#pragma once
#include "GameObject.h"
#include <vector>
#include <list>

class ImportWorld
{

public:
	GameObject* List;
	windowInstance* windowRef;
	std::vector<std::vector<int>> mapMatrix;
	ImportWorld(windowInstance* thisWindow, GameObject* objectList[]);
	void CreateMap(int* mapArr, int r, int c, GameObject* objectList[]);
	~ImportWorld();
};

