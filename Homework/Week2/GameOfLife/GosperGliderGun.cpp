#include "GosperGliderGun.h"

GosperGliderGun::GosperGliderGun(int** points, int x, int y)
{
	//Left Block
	points[x][y + 2] = 1;
	points[x + 1][y + 2] = 1;
	points[x][y + 3] = 1;
	points[x + 1][y + 3] = 1;

	//Left Segment
	x += 6;

	points[x + 2][y] = 1;
	points[x + 3][y] = 1;
	points[x + 1][y + 1] = 1;
	points[x + 5][y + 1] = 1;//
	points[x][y + 2] = 1;
	points[x + 6][y + 2] = 1;
	points[x][y + 3] = 1;//
	points[x + 4][y + 3] = 1;
	points[x + 6][y + 3] = 1;
	points[x + 7][y + 3] = 1;//
	points[x][y + 4] = 1;
	points[x + 6][y + 4] = 1;
	points[x + 1][y + 5] = 1;
	points[x + 5][y + 5] = 1;
	points[x + 2][y + 6] = 1;
	points[x + 3][y + 6] = 1;

	//Right Segment
	x += 8;

	points[x][y] = 1;
	points[x + 1][y] = 1;
	points[x][y + 1] = 1;
	points[x + 1][y + 1] = 1;//
	points[x][y + 2] = 1;
	points[x + 1][y + 2] = 1;//
	points[x + 2][y - 1] = 1;
	points[x + 2][y + 3] = 1;//
	points[x + 4][y - 1] = 1;
	points[x + 4][y + 3] = 1;
	points[x + 4][y - 2] = 1;
	points[x + 4][y + 4] = 1;

	//Right Block
	x += 9;

	points[x][y] = 1;
	points[x + 1][y] = 1;
	points[x][y + 1] = 1;
	points[x + 1][y + 1] = 1;
}