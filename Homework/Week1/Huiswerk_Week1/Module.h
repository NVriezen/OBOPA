#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Student.h"
#include "Docent.h"

class Module {
public:
	Module(std::string newName, int amountEC);
	void AddStudent(Student newStudent);
	void AssignTeacher(Docent doc);
	void DeleteStudent(Student stud);
	void DeleteStudent(int index);
	std::string Name();
	Docent GetAssignedTeacher();
	std::vector<Student> GetStudentList();
	int GetECAmount();
private:
	std::string name;
	int ec;
	Docent assignedTeacher;
	std::vector<Student> *studentList;
};