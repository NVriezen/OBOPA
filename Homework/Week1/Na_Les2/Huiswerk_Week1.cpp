// Huiswerk_Week1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
///------///

#include "Module.h"

#include <vector>
#include <iostream>

void PrintList(std::vector<Module*> modules);

int main()
{
	//instantiate new modules and add them to vector.
	std::vector<Module*> modules;
	{
		Module *mod = new Module("Sound, Game and Interaction Design", 1);
		modules.push_back(mod);
		mod = new Module("Object Oriented Programming Advanced", 2);
		modules.push_back(mod);
		mod = new Module("Game Development Kernmodule", 5);
		modules.push_back(mod);
	}

	//Instantiate Docenten, assign them to modules and add them to vector
	std::vector<Docent*> docenten;
	for (int i = 0; i < 3; i++) {
		Docent *doc = new Docent("Docent", "Teacher");
		modules.at(i)->assignTeacher(doc);
		docenten.push_back(doc);
	}

	//std::cout << "docenten created" << std::endl;

	//Instantiate Studenten, assign them to modules and add them to vector.
	std::vector<Student*> studenten;
	for (int i = 0; i < 10; i++) {
		Student* stud = new Student("Jan", "Janssen");
		//modules->at(0).AddStudent(stud);
		for (int j = 0; j < ((rand() % 3) + 1) ; j++) {
			modules.at(j)->addStudent(stud);
			//stud->addModule(modules.at(j));
		}
		studenten.push_back(stud);
	}

	//std::cout << "studenten created and added" << std::endl;

	//(1),(2)
	PrintList(modules);

	//(3)
	//wijzig EC
	modules.at(0)->setEC(4);
	//update voor alle 
	std::vector<Student*>::iterator it = studenten.begin();

	while (it != studenten.end()) {
		(*it)->updateEC(&modules);
	}
	PrintList(modules);

	//(4)
	modules.at(0)->deleteStudent(studenten.at(2));
	PrintList(modules);

    return 0;
}

void PrintList(std::vector<Module*> modules) {
	std::cout << "----- Start List -----" << std::endl;
	for (auto &modul : modules) {
		std::cout << "Module: " << modul->name() << std::endl;
		std::cout << "    Assigned Teacher: " << modul->getAssignedTeacher()->name() << std::endl;
		std::cout << "        Total Students: " << modul->getStudentList().size() << std::endl;
		for (auto &studen : modul->getStudentList()) {
			std::cout << "            " << studen->name() << " --- " << modul->getECAmount() << " points of his/her total of: " << studen->getTotalEC() << std::endl;
		}
	}
	std::cout << "----- End List -----" << std::endl;
}

