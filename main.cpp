// PA Scripting and Programming - Applications - Avraham Gross.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "roster.h"

using namespace std;

int main()
{
    
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Avraham,Gross,agros84@wgu.edu,26,10,8,13,SOFTWARE" };

    cout << "C867 Scripting and Programming: Applications" << endl << "Language: C++" << endl << "Student ID: 009965073" << endl << "Name: Avraham Gross \n" << endl;
    
    Roster classRoster(studentData); //Create Roster object classRoster, incorporates parse function on studentData[]
    classRoster.printAll(); //Prints all Student data
    classRoster.printInvalidEmails(); //Prints invalid email addresses in classRoster
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID()); //Prints average days in course for each Student
    }
    cout << endl;
    classRoster.printByDegreeProgram(Degree::DegreeProgram::SOFTWARE); //Prints Students with Degree Plan of "Software"
    classRoster.remove("A3"); //Removes Student at ID "A3"
    classRoster.printAll(); //Prints all Student data
    classRoster.remove("A3"); //Prints no Student found with ID "A3"

    


    return 0;
}
