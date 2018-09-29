#include "Shaman.h"

#include <iostream>

Shaman::Shaman(NPC* n) : DecoratorNPC(n) {}

void Shaman::render()
{
	DecoratorNPC::render();
	std::cout << "My role is Shaman." << std::endl;
}
