#pragma once

#include "NPC.h"

//Base Decorator Class for NPC
class DecoratorNPC : public NPC {
public:
	DecoratorNPC(NPC *n);
	~DecoratorNPC();

	/*virtual*/
	void render();
private:
	NPC * npc;
};