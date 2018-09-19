#pragma once
#include <string>
#include <vector>

class Module;
//#include "Module.h"

class Student {
public:
	Student(std::string first = "", std::string last = "");
	std::string Name();
	void UpdateEC();
	int GetTotalEC();
	void AddModule(Module *modul);
	void DeleteModule(Module *modul);
private:
	std::string name[2]; //Should be an array of first and last name
	int totalEC;
	std::vector<Module*> signedInModules;
};