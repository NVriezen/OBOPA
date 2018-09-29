#include "RuleApplier.h"

void RuleApplier::applyRules(GameRules* rulesChecker, int** point)
{
	//Creating 2D Array
	int** newGrid = new int*[128]; //Make new pointer to pointer
	for (int g = 0; g < 128; ++g) { //Make new pointer for pointer array
		newGrid[g] = new int[128]; //
	}

	int neighbours = 0;

	//Loop through the grid
	for (int y = 0; y < 128; y++) {
		for (int x = 0; x < 128; x++) {
			//Loop through nearby cells to look for neighbours
			for (int yNeighbour = y - 1; yNeighbour <= y + 1; yNeighbour++) {
				for (int xNeighbour = x - 1; xNeighbour <= x + 1; xNeighbour++) {
					if (xNeighbour == x && yNeighbour == y) { //If point is cell's location
						continue;
					}
					else if (((xNeighbour >= 0 && xNeighbour < 128) && (yNeighbour >= 0 && yNeighbour < 128)) && point[xNeighbour][yNeighbour] == 1) { //Check if point is inside grid && actived
						neighbours++;
					}
				}
			}

			newGrid[x][y] = rulesChecker->RulesCheck(neighbours, point[x][y]);
		}
	}
	//point = newGrid;
	//delete newGrid;

	for (int r = 0; r < 128; ++r) { //Make new pointer for pointer array
		for (int t = 0; t < 128; ++t) { //Make new pointer for pointer array
			point[t][r] = newGrid[t][r];//
		}
	}

	delete newGrid;

	//return point;
}
