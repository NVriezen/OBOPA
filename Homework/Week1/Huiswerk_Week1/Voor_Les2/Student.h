#pragma once
#include <string>
#include <vector>

class Module;
//#include "Module.h"

class Student {
public:
	Student(std::string first = "", std::string last = "");
	std::string name();
	void updateEC();
	int getTotalEC();
	void addModule(Module *modul);
	void deleteModule(Module *modul);
private:
	std::string names[2]; //Should be an array of first and last name
	int totalEC;
	std::vector<Module*> signedInModules;
};