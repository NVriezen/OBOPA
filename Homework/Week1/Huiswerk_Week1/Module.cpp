#include "stdafx.h"
#include "Module.h"

Module::Module(std::string newName, int amountEC)
{
	name = newName;
	ec = amountEC;
}

void Module::AddStudent(Student newStudent)
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

std::string Module::Name() {
	return name;
}

std::vector<Student> Module::GetStudentList() {
	return *studentList;
}


void Module::AssignTeacher(Docent doc)
{
	//check if assigned teacher is null
	//assign given teacher
	if (assignedTeacher.Name() != doc.Name()) {
		assignedTeacher = doc;
	}
}

Docent Module::GetAssignedTeacher() {
	return assignedTeacher;
}

void Module::DeleteStudent(Student stud) {
	std::vector<Student>::iterator it = studentList->begin();

	while (it != studentList->end()) {
		if (it->Name() == stud.Name()) {
			studentList->erase(it);
			break;
		}
		it++;
	}

	stud.DeleteModule(this);
}

void Module::DeleteStudent(int index) {
	studentList->erase(studentList->begin() + index);
}

int Module::GetECAmount() {
	return ec;
}