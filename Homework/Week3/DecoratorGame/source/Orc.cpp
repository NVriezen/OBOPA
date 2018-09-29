#include "Orc.h"

#include <iostream>

Orc::Orc(std::string n)
{
	name = n;
}

void Orc::render()
{
	std::cout << "My name is " << name << " and I am an Orc." << std::endl;
}
