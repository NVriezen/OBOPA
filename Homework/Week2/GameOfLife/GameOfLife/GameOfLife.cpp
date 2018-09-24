// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

#include "MatrixDrawer.h"
#include "OriginalRules.h"

#include "Block.h"
#include "Glider.h"

GameRules *SetGameRules() {
	return new OriginalRules;
}

int main()
{
	MatrixDrawer *matrix = new MatrixDrawer();

	GameRules *rules = SetGameRules();

	int** point = new int*[25];
	//int(*point)[25] = p;

	for (int a = 0; a < 25; ++a)
		point[a] = new int[25];

	for (int it = 0; it < 25; it++) {
		for (int ite = 0; ite < 25; ite++) {
			point[ite][it] = 0;
		}
	}

	// 0 1 2
	//------
	// X O X
	// X X O
	// O O O
	/*
	point[1][10 - 1] = 1;
	point[1 + 1][10] = 1;
	point[1][10 + 1] = 1;
	point[1 - 1][10 + 1] = 1;
	point[1 + 1][10 + 1] = 1;
	*/

	/*
	point[1 + 1][11] = 1;
	point[1 + 1][12] = 1;
	point[1 + 1][13] = 1;
	point[3][11] = 1;
	point[1][12] = 1;
	*/

	point[3][11] = 1;
	point[4][11] = 1;
	point[5][11] = 1;


	Block block1(point, 5, 5);
	Glider glider1(point, 10, 10);

	do {
		system("CLS"); //clear console
		matrix->drawMatrix(rules, point);
		Sleep(2000);
	} while (true);

	std::cout << "done" << std::endl;

    return 0;
}

