#pragma once
#include <string>
#include <vector>

class Module;
//#include "Module.h"

class Student {
public:
	Student(std::string first = "", std::string last = "");
	std::string name();
	void updateEC(std::vector<Module*> *modules);
	int getTotalEC();
private:
	std::string names[2]; //Should be an array of first and last name
	int totalEC;
};