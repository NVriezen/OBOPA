#include "stdafx.h"
#include "OriginalRules.h"

int OriginalRules::RulesCheck(int neighbours, int points) {
	/*
	if (neighbours == maxNum) {
		(*points) = 1;
		return true;
	} else if (neighbours > maxNum || neighbours < minNum) {
		(*points) = 0;
		return false;
	} else if ((neighbours == maxNum || neighbours == minNum) && (*points) == 1) {
		return true;
	}
	else {
		return false;
	}
	*/

	/*
	if ((*points) == 1) {
		if (neighbours > maxNum || neighbours < minNum) {
			(*points) = 0;
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (neighbours == maxNum) {
			(*points) = 1;
			return true;
		}
		else {
			(*points) = 0;
			return false;
		}
	}
	*/
	int nextState = points;
	if (nextState == 0) {
		if (neighbours == 3) {
			nextState == !nextState;
			return true;
		}
		//return false;
	}
	else {
		if (neighbours > 3 || neighbours < 2) {
			nextState == !nextState;
			return false;
		}
		//return true;
	}
	//return nextState;
}
