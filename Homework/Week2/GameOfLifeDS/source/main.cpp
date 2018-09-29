/*---------------------------------------------------------------------------------

	$Id: main.cpp,v 1.0 2018-09-27 20:28 $

	Simple console Game of Life demo
	-- NVriezen


---------------------------------------------------------------------------------*/
///NDS specific
#include <nds.h>

#include <stdio.h>
#include <stdlib.h>

//#include <iostream>

//#include "MatrixDrawer.h"
#include "OriginalRules.h"
#include "RandomRules.h"
#include "CustomRules.h"
#include "NoRules.h"

///NDS specific
#include "GridDrawer.h"
#include "RuleApplier.h"
#include <nds/system.h>

//Lifeforms
#include "Block.h"
#include "Glider.h"
#include "Beehive.h"
#include "Loaf.h"
#include "Blink.h"
#include "Toad.h"
#include "GosperGliderGun.h"

void startColor() {
	int x, y;

	//set the mode to allow for an extended rotation background
	videoSetMode(MODE_5_2D);
	videoSetModeSub(MODE_5_2D);

	//allocate a vram bank for each display
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	//create a background on each display
	int bgMain = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	int bgSub = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	u16* videoMemoryMain = bgGetGfxPtr(bgMain);
	u16* videoMemorySub = bgGetGfxPtr(bgSub);


	//initialize it with a color
	for (x = 0; x < 256; x++)
		for (y = 0; y < 256; y++)
		{
			videoMemoryMain[x + y * 256] = ARGB16(1, 31, 0, 0);
			videoMemorySub[x + y * 256] = ARGB16(1, 0, 0, 31);
		}
}


GameRules *SetGameRules() {
	return new OriginalRules;
	//return new RandomRules;
	return new CustomRules;
	//return new NoRules;
}
	
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	//initVideo();

	startColor();

	GridDrawer* grid = new GridDrawer;
	RuleApplier* ruler = new RuleApplier;

	//const int rows = 10;
	//const int columns = 10;
	//MatrixDrawer *matrix = new MatrixDrawer(&rows, &columns);

	GameRules *rules = SetGameRules();

	//Creating 2D Array
	int** point = new int*[128]; //Make new pointer to pointer
	for (int a = 0; a < 128; ++a) { //Make new pointer for pointer array
		point[a] = new int[128]; //
	}

	//Making sure the 2D array is initialised with only 0's
	for (int it = 0; it < 128; it++) {
		for (int ite = 0; ite < 128; ite++) {
			point[ite][it] = 0;
		}
	}

	//Instantiate some lifeforms
	Block block1(point, 5, 5);
	//Glider glider1(point, 10, 10);
	Beehive beehive1(point, 20, 2);
	Loaf loaf1(point, 12, 3);
	Blink blink1(point, 4, 12);
	Toad toad1(point, 5, 16);
	//GosperGliderGun(point, 80, 25);

	
	//Glider glider2(point, 60, 54);
	//Glider glider3(point, 30, 75);
	//Glider glider4(point, 10, 100);
	//Glider glider5(point, 66, 120);
	

	//Our infinite loop to draw the matrix
	while (true) {
		//point = ruler->applyRules(rules, point, newGrid);
		ruler->applyRules(rules, point);
		grid->drawGrid(point);

		swiWaitForVBlank();
	}

	return 0;
}
