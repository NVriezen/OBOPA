#include "Farmer.h"

#include <iostream>

Farmer::Farmer(NPC* n) : DecoratorNPC(n) {}

void Farmer::render()
{
	DecoratorNPC::render();
	std::cout << "My role is Farmer." << std::endl;
}