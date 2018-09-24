#include "stdafx.h"
#include "MatrixDrawer.h"
#include <iostream>
#include <vector>

#include <Windows.h>

void MatrixDrawer::drawMatrix(GameRules *rulesChecker, int **point)
{
	std::cout << "drawing size of " << dimensions[0] << "x" << dimensions[1] << std::endl;

	for (int y = 0; y < dimensions[1]; y++) {
		for (int x = 0; x < dimensions[0]; x++) {

			int neighbours = 0;
			for (int yNeighbour = y - 1; yNeighbour <= y + 1; yNeighbour++) {
				for (int xNeighbour = x - 1; xNeighbour <= x + 1; xNeighbour++) {
					if (xNeighbour == x && yNeighbour == y) {
						continue;
					}
					else if (((xNeighbour >= 0 && xNeighbour < dimensions[0]) && (yNeighbour >= 0 && yNeighbour < dimensions[1])) && point[xNeighbour][yNeighbour] == 1) { //check op map 
						//add neighbour
						neighbours++;
					}
				}
			}
			//Sleep(1);
			
			/*
			if (neighbours == 3) { //rules check
				point[j][i] = 1;
				//std::cout << "* ";
			}
			*/

			int i = rulesChecker->RulesCheck(neighbours, point[x][y]);
			std::cout << rulesChecker->RulesCheck(neighbours, point[x][y]);
			//std::cout << point[x][y];
			//std::cout << i;
			//point[x][y] = i;
			//std::cout << point[x][y];
			Sleep(50);
			if (i == 1) {
				//point[x][y] = i;
				std::cout << point[x][y];
				//Sleep(100);
				point[2][1] = 1;
				//point[1][0] = 1;
				point[0][1] = 1;
				point[1][1] = 1;
				std::cout << "X ";
			}
			else {
				//std::cout << point[x][y];
				//Sleep(100);
				point[x][y] = i;
				std::cout << ". ";
			}

		}
		std::cout << "\n";
	}
	std::cout << std::flush;

	/*
	int point[25][25];
	for (int y = dimensions[1] - 1; y < dimensions[1] + 1; y++) {
		for (int x = dimensions[0] - 1; x < dimensions[0] + 1; x++) {
			if (x == point[0] && y == point[0][0]) { //check op map 
				continue; // check in points list bool
				//add neighbour
				
			}
		}
	}
	*/
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
