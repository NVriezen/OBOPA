#pragma once

#include "DecoratorNPC.h"

//Decorator for NPC
class Soldier : public DecoratorNPC
{
public:
	Soldier(NPC* n);

	/*virtual*/
	void render();
};