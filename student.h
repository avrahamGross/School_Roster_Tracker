#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	//Constructors
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram);
	

	//Getter Functions
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge() const;
	int* getDaysInCourse();
	string getDegreeProgram() const;
	Degree::DegreeProgram getDegreeProgramEnum() const;

	//Setter Functions
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int daysNumber, int index);
	void setDegreeProgram(Degree::DegreeProgram degreeProgram);

	//Print Individual Student
	void print();


private:
	//Student variables
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[3];
	Degree::DegreeProgram degreeProgram;
};
#endif //!STUDENT_H

