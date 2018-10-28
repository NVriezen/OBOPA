///CHIP 8 Emulator by Niels Vriezen, 2018///

//Includes
#include "cpu.h"

#include <Windows.h>
#include <iostream>
//#include <time.h>
//#include <chrono>
//#include <thread>

CPU chip8;

void setKeys();
void drawGraphics();
unsigned char* loadFile(const char*, long*);

//------------------------------------------------------------------
int main(int argc, char** argv) {
	//long startFrame = time(0);
	//long endCycle;
	//int cycles = 0;
	unsigned char* buffer;
	long romSize;
	
	if (argv[1] != NULL) {
		buffer = loadFile(argv[1], &romSize); //Copy program into memory
	}
	else {
		return(1);
		//char name[4] = { 'pong' };
		///*DEBUG*/ buffer = rom; romSize = 1283;
	}

	chip8.initialize(); //Clear the memory, registers, screen
	chip8.loadGame(buffer, romSize); //Copy program into memory


	//System Loop
	while (1) {
		//Emulate one cycle
		chip8.emulateCycle();

		//If the draw flag is set, update the screen
		if (chip8.drawFlag) {
			drawGraphics();
		}

		//Store key press state (Press and Release)
		setKeys();

		/*
		cycles++;

		if (cycles >= 60) {
			endCycle = time(0);
			if ((endCycle - startFrame) < 1) {
				std::chrono::seconds w(1 - (endCycle - startFrame));
				std::this_thread::sleep_for(w);
			}
			startFrame = time(0);
			cycles = 0;
		}
		*/
		//std::cout << "The result of opcode: " << (chip8.opcode & 0xF000) << std::endl;
	}

	return 0;
}

void drawGraphics() {
	system("CLS");
	for (size_t row = 0; row < chip8.screenHeight; row++) {
		for (size_t column = 0; column < chip8.screenWidth; column++) {
			if (chip8.gfx[(row * chip8.screenWidth) + column] == 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	chip8.drawFlag = false;
}

void setKeys() {
	//for (auto k : chip8.key) {
	//	k = 0;
	//}

	if (GetAsyncKeyState('1') != 0) { chip8.key[0x1] = 1; }
	if (GetAsyncKeyState('1') == 0) { chip8.key[0x1] = 0; }
	if (GetAsyncKeyState('2') != 0) { chip8.key[0x2] = 1; }
	if (GetAsyncKeyState('2') == 0) { chip8.key[0x2] = 0; }
	if (GetAsyncKeyState('3') != 0) { chip8.key[0x3] = 1; }
	if (GetAsyncKeyState('3') == 0) { chip8.key[0x3] = 0; }
	if (GetAsyncKeyState('4') != 0) { chip8.key[0xC] = 1; }
	if (GetAsyncKeyState('4') == 0) { chip8.key[0xC] = 0; }
	if (GetAsyncKeyState('Q') != 0) { chip8.key[0x4] = 1; }
	if (GetAsyncKeyState('Q') == 0) { chip8.key[0x4] = 0; }
	if (GetAsyncKeyState('W') != 0) { chip8.key[0x5] = 1; }
	if (GetAsyncKeyState('W') == 0) { chip8.key[0x5] = 0; }
	if (GetAsyncKeyState('E') != 0) { chip8.key[0x6] = 1; }
	if (GetAsyncKeyState('E') == 0) { chip8.key[0x6] = 0; }
	if (GetAsyncKeyState('R') != 0) { chip8.key[0xD] = 1; }
	if (GetAsyncKeyState('R') == 0) { chip8.key[0xD] = 0; }
	if (GetAsyncKeyState('A') != 0) { chip8.key[0x7] = 1; }
	if (GetAsyncKeyState('A') == 0) { chip8.key[0x7] = 0; }
	if (GetAsyncKeyState('S') != 0) { chip8.key[0x8] = 1; }
	if (GetAsyncKeyState('S') == 0) { chip8.key[0x8] = 0; }
	if (GetAsyncKeyState('D') != 0) { chip8.key[0x9] = 1; }
	if (GetAsyncKeyState('D') == 0) { chip8.key[0x9] = 0; }
	if (GetAsyncKeyState('F') != 0) { chip8.key[0xE] = 1; }
	if (GetAsyncKeyState('F') == 0) { chip8.key[0xE] = 0; }
	if (GetAsyncKeyState('Z') != 0) { chip8.key[0xA] = 1; }
	if (GetAsyncKeyState('Z') == 0) { chip8.key[0xA] = 0; }
	if (GetAsyncKeyState('X') != 0) { chip8.key[0x0] = 1; }
	if (GetAsyncKeyState('X') == 0) { chip8.key[0x0] = 0; }
	if (GetAsyncKeyState('C') != 0) { chip8.key[0xB] = 1; }
	if (GetAsyncKeyState('C') == 0) { chip8.key[0xB] = 0; }
	if (GetAsyncKeyState('V') != 0) { chip8.key[0xF] = 1; }
	if (GetAsyncKeyState('V') == 0) { chip8.key[0xF] = 0; }
}

unsigned char* loadFile(const char* fileName, long* size){
	FILE* rom;
	long romSize;
	unsigned char* buffer;
	size_t result;

	errno_t errRom;
	errRom = fopen_s(&rom, fileName, "rb");

	if (rom != NULL) {
		fseek(rom, 0, SEEK_END);
		romSize = ftell(rom);
		rewind(rom);

		buffer = (unsigned char*)malloc(sizeof(unsigned char)*romSize); //char buffer[2048];
		if (buffer == NULL) {
			printf("Memory error");
			return nullptr;
		}
		//setvbuf(rom, buffer, _IOFBF, 2048);

		result = fread(buffer, 1, romSize, rom);
		if (result != romSize) {
			printf("Reading error");
			return nullptr;
		}
	}
	else {
		printf("Can't find file");
		return nullptr;
	}
	(*size) = romSize;
	return buffer;
};