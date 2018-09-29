#include "DecoratorNPC.h"

#include <iostream>

DecoratorNPC::DecoratorNPC(NPC * n)
{
	npc = n;
}

DecoratorNPC::~DecoratorNPC()
{
	delete npc;
}

void DecoratorNPC::render()
{
	npc->render();
}
