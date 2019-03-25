#pragma once
#include "GameObject.h"
#include <vector>

class ImportWorld
{

public:
	windowInstance* windowRef;
	std::vector<std::vector<int>> mapMatrix;
	ImportWorld(windowInstance* thisWindow);
	void CreateMap(int* mapArr, int r, int c);
	~ImportWorld();
};

