
#include "Loaf.h"

Loaf::Loaf(int** points, int x, int y)
{
	points[x - 1][y] = 1;
	points[x + 2][y] = 1;
	points[x][y + 1] = 1;
	points[x][y - 1] = 1;
	points[x + 1][y + 1] = 1;
	points[x + 1][y - 2] = 1;
	points[x + 2][y - 1] = 1;
}