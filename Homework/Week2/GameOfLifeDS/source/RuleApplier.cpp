#include "RuleApplier.h"

void RuleApplier::applyRules(GameRules* rulesChecker, int** point, int* height, int* width)
{
	//Creating 2D Array
	int** newGrid = new int*[*height]; //Make new pointer to pointer
	for (int g = 0; g < *height; ++g) { //Make new pointer for pointer array
		newGrid[g] = new int[*width]; //
	}

	int neighbours = 0;

	//Loop through the grid
	for (int y = 0; y < *height; y++) {
		for (int x = 0; x < *width; x++) {
			//Loop through nearby cells to look for neighbours
			for (int yNeighbour = y - 1; yNeighbour <= y + 1; yNeighbour++) {
				for (int xNeighbour = x - 1; xNeighbour <= x + 1; xNeighbour++) {
					if (xNeighbour == x && yNeighbour == y) { //If point is cell's location
						continue;
					}
					else if (((xNeighbour >= 0 && xNeighbour < *width) && (yNeighbour >= 0 && yNeighbour < *height)) && point[yNeighbour][xNeighbour] == 1) { //Check if point is inside grid && actived
						neighbours++;
					}
				}
			}

			newGrid[y][x] = rulesChecker->RulesCheck(&neighbours, point[y][x]);
		}
	}
	//point = newGrid;
	//delete newGrid;

	for (int r = 0; r < *height; ++r) { //Make new pointer for pointer array
		for (int t = 0; t < *width; ++t) { //Make new pointer for pointer array
			point[t][r] = newGrid[t][r];//
		}
	}

	for (int r = 0; r < *height; ++r) { //Make new pointer for pointer array
		delete[] newGrid[r];
	}
	delete[] newGrid;

	//return point;
}
