#pragma once

#include "NPC.h"

#include <string>

//NPC type
class Orc : public NPC {
public:
	Orc(std::string n);
	
	/*virtual*/
	void render();
private:
	std::string name;
};
