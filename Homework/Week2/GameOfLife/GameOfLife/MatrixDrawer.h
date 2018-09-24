#pragma once

#include "GameRules.h"

class MatrixDrawer {
public:
	//MatrixDrawer(int x, int y);
	int** drawMatrix(GameRules *rulesChecker, int **point);
	void SetDimensions(int x, int y);
	int* GetDimensions();
private:
	int dimensions[2] = { 25, 25 };
};