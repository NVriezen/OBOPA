#include "stdafx.h"
#include "Module.h"

#include <algorithm>
#include <iostream>

Module::Module(std::string newName, int amountEC)
{
	names = newName;
	ec = amountEC;
}

void Module::addStudent(Student newStudent)
{
	//if no list yet, make new one
	//assign student at back of list
	//maybe order them on alphabet
	if (studentList->size() == NULL) {
		//new studentList;
		std::vector<Student> *studentList = new std::vector<Student>;
	}
	studentList->push_back(newStudent);
	//maybe sort the list here
}

std::string Module::name() {
	return names;
}

std::vector<Student> Module::getStudentList() {
	return *studentList;
}


void Module::assignTeacher(Docent doc)
{
	//check if assigned teacher is null
	//assign given teacher
	if (assignedTeacher.name() != doc.name()) {
		assignedTeacher = doc;
	}
}

Docent Module::getAssignedTeacher() {
	return assignedTeacher;
}

void Module::deleteStudent(Student stud) {
	std::vector<Student>::iterator it = studentList->begin();

	while (it != studentList->end()) {
		if (it->name() == stud.name()) {
			studentList->erase(it);
			break;
		}
		it++;
	}

	stud.deleteModule(this);
}

void Module::deleteStudent(int index) {
	studentList->erase(studentList->begin() + index);
}

int Module::getECAmount() {
	return ec;
}

void Module::setEC(int input) {
	ec = input;
}