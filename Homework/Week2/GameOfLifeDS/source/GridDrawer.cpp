#include "GridDrawer.h"

#include <nds.h>
#include <nds/system.h>

void GridDrawer::drawGrid(int ** point)
{
	/*
	//Loop through the grid
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 256; x++) {
			if (point[x][y] == 1) {
				//std::cout << "X ";
			}
			else {
				//std::cout << ". ";
			}

		}
		//std::cout << "\n";
	}
	*/

	//std::cout << std::flush;
	int x, y;

	//create a background on each display
	int bgMain = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	int bgSub = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	u16* videoMemoryMain = bgGetGfxPtr(bgMain);
	u16* videoMemorySub = bgGetGfxPtr(bgSub);

	//initialize it with a color
	for (x = 0; x < 128; x++)
		for (y = 0; y < 128; y++)
		{
			if (point[x][y] == 1) {
				
				videoMemoryMain[2*x + 2*y * 256] = ARGB16(1, 31, 31, 31);
				videoMemoryMain[(2*x + 2*y * 256)+1] = ARGB16(1, 31, 31, 31);
				videoMemoryMain[(2*x + 2*y * 256)+256] = ARGB16(1, 31, 31, 31);
				videoMemoryMain[(2*x + 2*y * 256)+256+1] = ARGB16(1, 31, 31, 31);
				continue;
				
				//videoMemoryMain[x + y * 128] = ARGB16(1, 31, 31, 31);
			}
			else {
				
				videoMemoryMain[2 * x + 2 * y * 256] = ARGB16(1, 0, 0, 0);
				videoMemoryMain[(2 * x + 2 * y * 256) + 1] = ARGB16(1, 0, 0, 0);
				videoMemoryMain[(2 * x + 2 * y * 256) + 256] = ARGB16(1, 0, 0, 0);
				videoMemoryMain[(2 * x + 2 * y * 256) + 256 + 1] = ARGB16(1, 0, 0, 0);
				
				//videoMemoryMain[x + y * 128] = ARGB16(1, 0, 0, 0);
			}
			
			//videoMemoryMain[x + y * 256] = ARGB16(1, 31, 0, 0);
			//videoMemorySub[x + y * 256] = ARGB16(1, 0, 0, 31);
		}
}
