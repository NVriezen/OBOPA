#include "Elf.h"

#include <iostream>

Elf::Elf(std::string n)
{
	name = n;
}

void Elf::render()
{
	std::cout << "My name is " << name << " and I am an Elf." << std::endl;
}
