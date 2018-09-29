#pragma once

#include "DecoratorNPC.h"

//Decorator for NPC
class Shaman : public DecoratorNPC
{
public:
	Shaman(NPC* n);

	/*virtual*/
	void render();
};
