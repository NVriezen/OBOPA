#include "Blink.h"

Blink::Blink(int** points, int x, int y)
{
	points[x][y] = 1;
	points[x - 1][y] = 1;
	points[x + 1][y] = 1;
}