#include "ImportWorld.h"
#include <fstream>
#include <iostream>
#include <string>


ImportWorld::ImportWorld(windowInstance* thisWindow, GameObject* objectList[])
{
	windowRef = thisWindow;

	std::ifstream map("Maps/test1.lvl");
	std::string line;

	int rowCount = 0;
	int columnCount = 0;
	bool columnsCounted = false;

	// Initial check to get size of array (Rows/Columns)
	while (std::getline(map, line))
	{
		for (char& c : line)
		{
			if (c != ' ' && !columnsCounted)
			{
				columnCount++;
			}
		}

		columnsCounted = true;

		if (line[0] != '{')
		{
			rowCount++;
		}
	}
	map.close();

	//Set the map matrix to the correct size
	const int r = rowCount;
	const int c = columnCount;

	int* mapArr = new int[r*c];

	//Reread while inputting data
	//TODO: Can probably be tidied up into one simple step
	map.open("Maps/test1.lvl");
	rowCount = 0;
	while (std::getline(map, line))
	{
		if (line[0] == '{')
		{
			break;
		}

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != ' ')
			{
				int x = (int)line[i] - '0';
				mapArr[rowCount*c+i] = x;
			}
		}

		rowCount++;
	}
	map.close();

	CreateMap(mapArr, r, c, objectList);
}

void ImportWorld::CreateMap(int* mapArr, int r, int c, GameObject* objectList[])
{
	int counter = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << mapArr[i*c + j] << " ";

			int x = (j * 50) + 25;
			int y = i * 50;
			int id = mapArr[i * c + j];

			if (id == 1)
			{
				GameObject* newMapObject = new GameObject(windowRef, id, x, y, 50, 50, false, 1, 1, "block.png");
				objectList[counter] = newMapObject;
				counter++;
			}	
		}

		std::cout << "\n";
	}
}


ImportWorld::~ImportWorld()
{
}
