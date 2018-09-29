#pragma once

#include "DecoratorNPC.h"

//Decorator for NPC
class Farmer : public DecoratorNPC
{
public:
	Farmer(NPC* n);

	/*virtual*/
	void render();
};