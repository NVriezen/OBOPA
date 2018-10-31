#include "MatrixDrawer.h"

#include <iostream>
#include <time.h>

int timer = 0;

MatrixDrawer::MatrixDrawer(int rows, int columns)
{
	dimensions[0] = rows;
	dimensions[1] = columns;
}

void MatrixDrawer::drawMatrix(GameRules* rulesChecker, int** point)
{
	std::cout << "Drawing size of " << dimensions[0] << "x" << dimensions[1] << std::endl;

	timer++; //timer for slower speed

	//Create a new grid to save the changed values in
	int** newGrid = new int*[dimensions[1]];
	for (int g = 0; g < dimensions[1]; ++g) {
		newGrid[g] = new int[dimensions[0]];
	}

	//Loop through the grid
	for (int y = 0; y < dimensions[1]; y++) {
		for (int x = 0; x < dimensions[0]; x++) {

			int neighbours = 0;

			//Loop through nearby cells to look for neighbours
			for (int yNeighbour = y - 1; yNeighbour <= y + 1; yNeighbour++) {
				for (int xNeighbour = x - 1; xNeighbour <= x + 1; xNeighbour++) {
					if (xNeighbour == x && yNeighbour == y) { //If point is cell's location
						continue;
					}
					else if (((xNeighbour >= 0 && xNeighbour < dimensions[0]) && (yNeighbour >= 0 && yNeighbour < dimensions[1])) && point[xNeighbour][yNeighbour] == 1) { //Check if point is inside grid && actived
						neighbours++;
					}
				}
			}

			newGrid[x][y] = rulesChecker->RulesCheck(neighbours, point[x][y]);

			if (newGrid[x][y] == 1) {
				std::cout << "X ";
			}
			else {
				std::cout << ". ";
			}

		}
		std::cout << "\n";
	}

	std::cout << std::flush;

	//Making sure the 2D array is initialised with only 0's
	for (int it = 0; it < dimensions[0]; it++) {
		for (int ite = 0; ite < dimensions[1]; ite++) {
			point[ite][it] = newGrid[ite][it];
		}
	}

	//if (timer % 5 == 0) {
	//	timer = 0;
	//*point = *newGrid;
	//}
	//else {
	//	return point;
	//}
	delete[] newGrid;
	if (newGrid != nullptr) {
		std::cout << "Memory is NOT emptied" << std::endl;
	}
	//return point;
}

void MatrixDrawer::SetDimensions(int x, int y)
{
	dimensions[0] = x;
	dimensions[1] = y;
}

int* MatrixDrawer::GetDimensions()
{
	return dimensions;
}
