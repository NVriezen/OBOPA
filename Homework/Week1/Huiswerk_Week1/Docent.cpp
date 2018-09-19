#include "stdafx.h"
#include "Docent.h"

Docent::Docent(std::string first, std::string last)
{
	names[0] = first;
	names[1] = last;
}

std::string Docent::name()
{
	return names[0] + " " + names[1];
}
