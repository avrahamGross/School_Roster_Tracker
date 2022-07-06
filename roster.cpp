#include "roster.h"
#include<iostream>
#include<string>

using namespace std;
//Empty Roster Constructor:
Roster::Roster() {
	numOfStudents = 0;
	*classRosterArray = new Student[numOfStudents];
	
}
//Roster Constructor: automatically parses studentData[]
Roster::Roster(const string studentData[]) {
	*classRosterArray = new Student[5];
	numOfStudents = 0;
	this->parse(studentData);
}
//Roster Destructor:
Roster::~Roster() { 
	for (int i = 0; i < numOfStudents; ++i) {
		delete classRosterArray[i];
	}
	}
//Roster Copy Constructor:
Roster::Roster(const Roster& roster){
	*classRosterArray = new Student[roster.numOfStudents];
	*classRosterArray = *(roster.classRosterArray);
	this->numOfStudents = roster.numOfStudents;
}
//Roster Copy Assignment Operator:
Roster& Roster::operator=(const Roster& roster)
{
	if (this != &roster) {
		delete *this->classRosterArray;
		*Roster::classRosterArray = new Student[5];
		*Roster::classRosterArray = *(roster.classRosterArray);
	}
	return *this;
}

//Parse studentData[]
void Roster::parse(const string studentData[]) {
	for (int i = 0; i < 5; ++i) { //Loop through Student objects
		int position = 0;
		int nextComma = 0;
		string individualStudentData[9]; //Array to hold individial Student data
		for (int index = 0; index < 9; ++index) {//Parse individual students data to individualStudentData array
			nextComma = studentData[i].find(",", position);
			individualStudentData[index] = studentData[i].substr(position, (nextComma - position));
			position = nextComma + 1;
		}

		int age = stoi(individualStudentData[4]);//Convert necesary strings to ints
		int class1 = stoi(individualStudentData[5]);//Convert necesary strings to ints
		int class2 = stoi(individualStudentData[6]);//Convert necesary strings to ints
		int class3 = stoi(individualStudentData[7]);//Convert necesary strings to ints

		Degree::DegreeProgram degreeProgram; //Convert string to Degree::DegreeProgram
		if (individualStudentData[8] == "SECURITY") {
			degreeProgram = Degree::SECURITY;
		}
		else if (individualStudentData[8] == "NETWORK") {
			degreeProgram = Degree::NETWORK;
		}
		else {
			degreeProgram = Degree::SOFTWARE;
		}

		//Calls add() on individual Student
		Roster::add(individualStudentData[0], individualStudentData[1], individualStudentData[2], individualStudentData[3], age,
			class1, class2, class3,degreeProgram);
	}

}

void Roster::add(string& studentID, string& firstName, string& lastName, string& email, int& age, int& daysInCourse1,
				 int& daysInCourse2, int& daysInCourse3, Degree::DegreeProgram& degreeProgram) {
	//Assigns appropriate index in pointer array to location of new student
	classRosterArray[numOfStudents] = new Student(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	numOfStudents = numOfStudents + 1; //Increments Student count
}

void Roster::remove(string studentID) { //Remove Student at ID of argument
	cout << "Removing Student " << studentID << endl;
	bool found = false; //Determines which branch to take
	for (int i = 0; i < numOfStudents; ++i) { //Iterate through Students looking for ID of argument
		if (classRosterArray[i]->getStudentID() == studentID) { //If found
			found = true;
			cout << "Student " << studentID << " is deleted. \n" << endl;
			++i;
			for (i; i < numOfStudents; ++i) { //Relocates remaining Students in array in order to move empty spot to last index
				classRosterArray[i-1] = classRosterArray[i];
			}
			classRosterArray[i-1] = NULL;
			--numOfStudents; //Decrements Student count
			break;
		}
		}
	if (!found) { //If not found
		cout << "There is no student with ID " << studentID << ". \n" << endl;
	}
}

void Roster::printAll() { //Prints each Student object
	for (int i = 0; i < numOfStudents; ++i) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) { //Prints average days in course
	int i = 0;
	while (i < numOfStudents) { //Finds index of correct student based on argument string
		if (classRosterArray[i]->getStudentID() == studentID) {
			break;
		}
		else {
			++i;
		}
	}
	int average = 0;
	for (int x = 0; x < 3; ++x) { //Accumulate total days for each course
		average += (classRosterArray[i]->getDaysInCourse()[x]);
	}
	cout << "Student " << studentID << "'s average days in course: " << average / 3 << endl; //Output average
}

void Roster::printInvalidEmails() { //Prints invalid emails in Student data
	cout << "Invalid Emails: \n" << endl;
	for (int i = 0; i < numOfStudents; ++i) { //Iterates through array of Student pointers
		string email = classRosterArray[i]->getEmail();
		if (email.find('@') == std::string::npos || email.find('.') == std::string::npos  //Checks for invalid email syntax
			|| email.find(" ") != std::string::npos) {
				cout << email << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(Degree::DegreeProgram degreeProgram) { //Prints Sudents with matching Degree Program
	string degProgram[] = {"SECURITY","NETWORK","SOFTWARE"}; //Use enum value to reference index in array for corresponding Degree Program name 
	cout << "Degree Program: " << degProgram[degreeProgram] << endl;
	for (int i = 0; i < numOfStudents; ++i) {
		if ((classRosterArray[i]->getDegreeProgramEnum()) == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

