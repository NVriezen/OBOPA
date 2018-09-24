#include "stdafx.h"

#include "Block.h"

Block::Block(int **points, int x, int y)
{
	points[x][y] = 1;
	points[x+1][y] = 1;
	points[x][y+1] = 1;
	points[x+1][y+1] = 1;
}
