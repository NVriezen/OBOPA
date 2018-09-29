#include "Soldier.h"

#include <iostream>

Soldier::Soldier(NPC* n) : DecoratorNPC(n) {}

void Soldier::render()
{
	DecoratorNPC::render();
	std::cout << "My role is Soldier." << std::endl;
}