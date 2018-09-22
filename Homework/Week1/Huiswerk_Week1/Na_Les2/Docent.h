#pragma once
#include <string>
class Docent {
public:
	Docent(std::string first = "", std::string last = "");
	std::string name();
private:
	std::string names[2]; //should be an array for first and last name;
};