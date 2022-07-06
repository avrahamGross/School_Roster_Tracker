#include <iostream>
#include <string>
#include "student.h"
using namespace std;

	//Empty Student Constructor:
	Student::Student() { 
		this->studentID;
		this->firstName;
		this->lastName;
		this->email;
		this->age = NULL;
		this->daysInCourse[0] = NULL;
		this->daysInCourse[1] = NULL;
		this->daysInCourse[2] = NULL;
		this->degreeProgram;
	}

	//Student Constructor
	Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1,
					 int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram) {
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->age = age;
		this->daysInCourse[0] = daysInCourse1;
		this->daysInCourse[1] = daysInCourse2;
		this->daysInCourse[2] = daysInCourse3;
		this->degreeProgram = degreeProgram;
		}
	
	//Getter Functions:
	string Student::getStudentID() const {
		return studentID;
	}

	string Student::getFirstName() const {
		return firstName;
	}

	string Student::getLastName() const {
		return lastName;
	}

	string Student::getEmail() const {
		return email;
	}

	int Student::getAge() const {
		return age;
	}

	int* Student::getDaysInCourse() { //Array of pointers to hold data for Roster::printAverageDaysInCourse() Function
		int* numOfDays[3];
		for (int i = 0; i < 3; ++i) {
			numOfDays[i] = &daysInCourse[i];
		}
		
		return *numOfDays;
	}

	string Student::getDegreeProgram() const {
		string arrayOfValue[] = { "SECURITY" , "NETWORK" , "SOFTWARE" };
		string programValue = "";
		for (int i = 0; i < 3; ++i) { //Convert enum value to string for Student::Print() Function
			if (i == this->degreeProgram) {
				programValue = arrayOfValue[i];
				break;
			}
		}
		return programValue;
	}

	Degree::DegreeProgram Student::getDegreeProgramEnum() const { //Made to simplify the Roster::printByDegreeProgram() Function
		return this->degreeProgram;								  //to compare two DegreeProgram enum values instead of comparing string value
	}

	//Setter Functions:
	void Student::setStudentID(string studentID) {
		this->studentID = studentID;
	}

	void Student::setFirstName(string firstName) {
		this->firstName = firstName;
	}

	void Student::setLastName(string lastName) {
		this->lastName = lastName;
	}

	void Student::setEmail(string email) {
		this->email = email;
	}

	void Student::setAge(int age) {
		this->age = age;
	}

	void Student::setDaysInCourse(int daysNumber, int index) {
		daysInCourse[index] = daysNumber;
	}

	void Student::setDegreeProgram(Degree::DegreeProgram degreeProgram) {

		this->degreeProgram = degreeProgram;
	}

	//Print Individual Student Data:
	void Student::print() {
		cout << studentID << "\t First Name: " << firstName << "\t Last Name: " << lastName << "\t Age: " << age << "\t daysInCourse: {"
			<< daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} \t DegreeProgram: "  << this->getDegreeProgram()  << endl;
	}



