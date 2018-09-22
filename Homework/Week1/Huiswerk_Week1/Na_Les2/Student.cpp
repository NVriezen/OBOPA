#include "stdafx.h"
#include "Student.h"

#include <algorithm>

//Students have an array of first and last name
Student::Student(std::string first, std::string last) {
	names[0] = first;
	names[1] = last;
	totalEC = 0;
}

std::string Student::name() {
	return names[0] + " " + names[1];
}

int Student::getTotalEC() {
	return totalEC;
}

/*
//Add Module to student's modules List
void Student::addModule(Module *modul) {
	//if no list yet, make new one
	//assign student at back of list
	//maybe order them on alphabet
	if (signedInModules.empty()) {
		//new studentList;
		std::vector<Student*> signedInModules;
	}
	signedInModules.push_back(modul);
}
*/

/*
//Delete module from the modules list
void Student::deleteModule(Module* modul) {	
	for (size_t i = 0; i < signedInModules.size(); i++) {
		if (signedInModules.at(i) == modul) {
			signedInModules.erase(signedInModules.begin() + i);
			break;
		}
	}
}
*/

void Student::updateEC(std::vector<Module*> *modules) {
	totalEC = 0;

	//std::vector<Student*>::iterator i;
	std::vector<Module*>::iterator it = modules->begin();

	while (it != modules->end()) {
		//Ik kan hier niet via de pointers in de vector dingen opvragen van een object.
		//dus het volgende kan niet
		//(*it)->getStudentList();
		//Dit heb ik echter wel nodig om de ECs te berekenen en ik snap niet waarom dit niet kan.
	}
}