
#include "CustomRules.h"

int CustomRules::RulesCheck(int* neighbours, int points)
{
	int newCell = points;
	if (newCell == 0) {
		if (*neighbours % 2 == 0) { //Condition for reproduction
			newCell = 1;
		}
	}
	else {
		if (*neighbours == 8 || *neighbours == 3 || (*neighbours % 3 == 0)) { //Condition for Death
			newCell = 0;
		}
	}
	return newCell; //Return new value of cell
}
