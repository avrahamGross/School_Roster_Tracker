#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include<iostream>
#include<string>
#include "student.h"
using namespace std;

class Roster
{
public:
	/*Constructors and Destructor:*/
	Roster();
	Roster(const string studentData[]);
	~Roster();
	Roster(const Roster& roster);
	Roster& operator=(const Roster& classRosterArray);

	/*Roster Functions:*/
	void parse(const string studentData[]);
	void add(string& studentID, string& firstName, string& lastName, string& email, int& age, int& daysInCourse1, int& daysInCourse2, int& daysInCourse3, Degree::DegreeProgram& degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree::DegreeProgram degreeProgram);
	Student* classRosterArray[5];
private:
	/*Roster variables:*/
	int numOfStudents;
		
};

#endif // !ROSTER_H