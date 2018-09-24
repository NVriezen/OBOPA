#pragma once

#include "GameRules.h"

class OriginalRules : public GameRules {
public:
	int RulesCheck(int neighbours, int points);

private:
	int minNum = 2;
	int maxNum = 3;
};