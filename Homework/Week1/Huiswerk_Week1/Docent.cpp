#include "stdafx.h"
#include "Docent.h"

Docent::Docent(std::string first, std::string last)
{
	name[0] = first;
	name[1] = last;
}

std::string Docent::Name()
{
	return name[0] + " " + name[1];
}
