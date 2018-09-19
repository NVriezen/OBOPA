// Huiswerk_Week1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
///------///

//#include "Student.h"
#include "Module.h"

#include <vector>
#include <iostream>

void PrintList(std::vector<Module> *modules);

int main()
{
	//instantiate new modules and add them to vector.
	std::vector<Module> *modules = new std::vector<Module>;
	{
		Module mod = Module("Sound, Game and Interaction Design", 1);
		modules->push_back(mod);
		mod = Module("Object Oriented Programming Advanced", 2);
		modules->push_back(mod);
		mod = Module("Game Development Kernmodule", 5);
		modules->push_back(mod);
	}

	//Instantiate Docenten, assign them to modules and add them to vector
	std::vector<Docent> *docenten = new std::vector<Docent>;
	for (int i = 0; i < 3; i++) {
		Docent doc = Docent("Docent", "Teacher");
		modules->at(i).AssignTeacher(doc);
		docenten->push_back(doc);
	}

	//Instantiate Studenten, assign them to modules and add them to vector.
	std::vector<Student> *studenten = new std::vector<Student>;
	for (int i = 0; i < 10; i++) {
		Student stud = Student("Jan", "Janssen");
		//modules->at(0).AddStudent(stud);
		for (int j = 0; j < ((rand() % 3) + 1) ; j++) {
			modules->at(j).AddStudent(stud);
			stud.AddModule(&modules->at(j));
		}
		studenten->push_back(stud);
	}

	//(1),(2)
	PrintList(modules);

	//(3)
	//wijzig EC
	//update voor alle studenten
	studenten->at(2).GetTotalEC(); //dit is maar voor 1
	PrintList(modules);

	//(4)
	modules->at(0).DeleteStudent(studenten->at(2));
	PrintList(modules);
	
	/*
	for (auto &modul : *modules) {
		std::cout << "Module: " << modul.Name() << std::endl;
		std::cout << "Assigned Teacher: " << modul.GetAssignedTeacher().Name() << std::endl;
		std::cout << "Total Student: " << modul.GetStudentList().size() << std::endl;

	}
	std::cout << "Studentlist: " << modules->at(0).GetStudentList().at(0).Name() << std::endl;
	for (auto &studen : *studenten) {
		std::cout << "Student" << std::endl;
	}
	for (auto &docen : *docenten) {
		std::cout << "Docent" << std::endl;
	}
	*/

    return 0;
}

void PrintList(std::vector<Module> *modules) {
	std::cout << "----- Start List -----" << std::endl;
	for (auto &modul : *modules) {
		std::cout << "Module: " << modul.Name() << std::endl;
		std::cout << "    Assigned Teacher: " << modul.GetAssignedTeacher().Name() << std::endl;
		std::cout << "        Total Students: " << modul.GetStudentList().size() << std::endl;
		for (auto &studen : modul.GetStudentList()) {
			std::cout << "            " << studen.Name() << " --- " << modul.GetECAmount() << " points of his/her total of: " << studen.GetTotalEC() << std::endl;
		}
	}
	std::cout << "----- End List -----" << std::endl;
}

