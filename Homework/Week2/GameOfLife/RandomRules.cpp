#include "RandomRules.h"

#include <random>
#include <time.h>

RandomRules::RandomRules() {
	srand(time(NULL));
	maxNum = rand() % 9;
	minNum = rand() % 9;
}

//Rules based on random numbers
int RandomRules::RulesCheck(int neighbours, int points) {
	int newCell = points;
	if (newCell == 0) {
		if (neighbours == maxNum) { //Condition for reproduction
			newCell = 1;
		}
	}
	else {
		if (neighbours > maxNum || neighbours < minNum) { //Condition for death
			newCell = 0;
		}
	}
	return newCell; //Return new value of cell
}