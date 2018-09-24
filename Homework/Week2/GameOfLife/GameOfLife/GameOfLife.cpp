// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include "MatrixDrawer.h"
#include "OriginalRules.h"
#include "RandomRules.h"
#include "CustomRules.h"

//Lifeforms
#include "Block.h"
#include "Glider.h"
#include "Beehive.h"
#include "Loaf.h"
#include "Blink.h"
#include "Toad.h"
#include "GosperGliderGun.h"

GameRules *SetGameRules() {
	return new OriginalRules;
	//return new RandomRules;
	//return new CustomRules;
}

int main()
{
	MatrixDrawer *matrix = new MatrixDrawer();

	GameRules *rules = SetGameRules();

	//Creating 2D Array
	int** point = new int*[25]; //Make new pointer to pointer
	for (int a = 0; a < 25; ++a) { //Make new pointer for pointer array
		point[a] = new int[25]; //
	}

	//Making sure the 2D array is initialised with only 0's
	for (int it = 0; it < 25; it++) {
		for (int ite = 0; ite < 25; ite++) {
			point[ite][it] = 0;
		}
	}

	//Instantiate some lifeforms
	Block block1(point, 5, 5);
	Glider glider1(point, 10, 10);
	Beehive beehive1(point, 20, 2);
	Loaf loaf1(point, 12, 3);
	Blink blink1(point, 4, 12);
	Toad toad1(point, 5, 16);
	//GosperGliderGun(point, 0, 14);

	//Our infinite loop to draw the matrix
	while (true) {
		system("CLS"); //clear console
		point = matrix->drawMatrix(rules, point);
		Sleep(18);
	}

	std::cout << "Done" << std::endl;

    return 0;
}

