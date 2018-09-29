#pragma once

#include "NPC.h"

#include <string>

//NPC type
class Elf : public NPC {
public:
	Elf(std::string n);

	/*virtual*/
	void render();
private:
	std::string name;
};