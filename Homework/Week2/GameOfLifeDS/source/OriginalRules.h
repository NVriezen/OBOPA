#pragma once

#include "GameRules.h"

class OriginalRules : public GameRules {
public:
	int RulesCheck(int*, int) override;

private:
	int minNum = 2;
	int maxNum = 3;
};