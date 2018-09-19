#include "stdafx.h"
#include "Student.h"

#include <algorithm>

//Students have an array of first and last name
Student::Student(std::string first, std::string last) {
	names[0] = first;
	names[1] = last;
	totalEC = 0;
	//std::vector<Student> *signedInModules = {};
}

std::string Student::name() {
	return names[0] + " " + names[1];
}

int Student::getTotalEC() {
	return totalEC;
}

void Student::updateEC() {
	totalEC = 0;

	std::vector<Module*>::iterator i = signedInModules.begin();

	//Iterate through modules list and get amount of EC
	while(i != signedInModules.end()) {
		totalEC += i->GetECAmount();
	}
}

//Add Module to student's modules List
void Student::addModule(Module *modul) {
	//if no list yet, make new one
	//assign student at back of list
	//maybe order them on alphabet
	if (signedInModules.empty()) {
		//new studentList;
		std::vector<Student> *signedInModules = {};
	}
	signedInModules.push_back(modul);
}

//Delete module from the modules list
void Student::deleteModule(Module *modul) {	
	for (size_t i = 0; i < signedInModules.size(); i++) {
		if (signedInModules.at(i) == modul) {
			signedInModules.erase(signedInModules.begin() + i);
			break;
		}
	}
}