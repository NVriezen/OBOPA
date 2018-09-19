#include "stdafx.h"
#include "Student.h"

#include <algorithm>

//Students have an array of first and last name
Student::Student(std::string first, std::string last) {
	name[0] = first;
	name[1] = last;
	totalEC = 0;
	std::vector<Student> *signedInModules = {};
}

std::string Student::Name() {
	return name[0] + " " + name[1];
}

int Student::GetTotalEC() {
	return totalEC;
}

void Student::UpdateEC() {
	totalEC = 0;

	/*
	std::vector<Module*>::iterator i = signedInModules.begin();

	while(i != signedInModules.end()) {
		*i.GetECAmount();
	}
	*/

	//for (int i = 0; i < signedInModules.size(); i++) {
	//	Module &mod = *signedInModules[i];
		//int amount = signedInModules[i]->GetECAmount();
	//}

	//for (size_t i = 0; i < signedInModules.size(); i++) {
	//	totalEC += signedInModules.at(i).GetECAmount;
	//}
}

void Student::AddModule(Module *modul) {
	//if no list yet, make new one
	//assign student at back of list
	//maybe order them on alphabet
	if (signedInModules.empty()) {
		//new studentList;
		std::vector<Student> *signedInModules = {};
	}
	signedInModules.push_back(modul);
}

void Student::DeleteModule(Module *modul) {
	/*
	std::vector<Module*>::iterator it = signedInModules.begin();
	
	while (it != signedInModules.end()) {
		if (it == modul) {
			signedInModules.erase(it);
			break;
		}
		it++;
	}
	*/

	
	for (size_t i = 0; i < signedInModules.size(); i++) {
		if (signedInModules.at(i) == modul) {
			signedInModules.erase(signedInModules.begin() + i);
			break;
		}
	}
	
	
	//modul.DeleteStudent(this);
}