#pragma once

#include "GameRules.h"

class RandomRules : public GameRules {
public:
	RandomRules();
	int RulesCheck(int*, int) override;
private:
	int minNum;
	int maxNum;
};