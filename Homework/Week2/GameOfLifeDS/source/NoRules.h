#pragma once

#include "GameRules.h"

class NoRules : public GameRules {
public:
	int RulesCheck(int*, int) override;
};
