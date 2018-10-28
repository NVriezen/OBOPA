#pragma once

#include <string>
#include <vector>

//class Student;
#include "Student.h"
#include "Docent.h"

class Module {
public:
	Module(std::string newName, int amountEC);
	void addStudent(Student* newStudent);
	void assignTeacher(Docent* doc);
	void deleteStudent(Student* stud);
	void deleteStudent(int index);
	std::string name();
	Docent* getAssignedTeacher();
	std::vector<Student*> getStudentList();
	int getECAmount();
	void setEC(int input);
private:
	std::string names;
	int ec;
	Docent* assignedTeacher;
	std::vector<Student*> studentList;
};