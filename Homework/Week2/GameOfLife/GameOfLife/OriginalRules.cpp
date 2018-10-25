#include "OriginalRules.h"

int OriginalRules::RulesCheck(int neighbours, int points) {
	int nextState = points;
	if (nextState == 0) {
		if (neighbours == 3) { //Condition for reproduction
			nextState = 1;
		}
	}
	else {
		if (neighbours > 3 || neighbours < 2) { //Condition for Death
			nextState = 0;
		}
	}
	return nextState; //Return new value of cell
}
