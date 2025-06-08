#include "roster.h"
#include <iostream>

using namespace std;

int Roster::nextIndex = 0;

Roster::Roster() {
    classRosterArray = new Student[5];
}

Roster::~Roster() {
    delete[] classRosterArray;
}

void Roster::parse(string data) {
    size_t rhs = data.find(",");
    string studentID = data.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string firstName = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string lastName = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string emailAddress = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int age = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    string degreeProgram = data.substr(lhs);

    DegreeProgram degreeProgramOutput = DegreeProgram::SOFTWARE;

    if (degreeProgram == "SECURITY") {
        degreeProgramOutput = DegreeProgram::SECURITY;
    } else if (degreeProgram == "NETWORK") {
        degreeProgramOutput = DegreeProgram::NETWORK;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgramOutput);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student s(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
    classRosterArray[nextIndex++] = s;
}

void Roster::remove(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i].getStudentID() == studentID) {
            classRosterArray[i].setStudentId("Invalid");
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found." << endl;
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        Student s = classRosterArray[i];
        if(s.getStudentID() != "Invalid") {
            s.print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i].getStudentID() == studentID) {
            int* courseDays = classRosterArray[i].getDaysToComplete();
            int total = courseDays[0] + courseDays[1] + courseDays[2];
            cout << "Average days in course for student " << studentID << " = " << (total / 3.0) << endl;
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found." << endl;
}

void Roster::printDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i].getDegreeProgram() == degreeProgram) {
            classRosterArray[i].print();
        }
        
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; i++) {
        string email = classRosterArray[i].getEmailAddress();
        if (email.find('@') == string::npos || 
            email.find('.') == string::npos || 
            email.find(' ') != string::npos) {
            cout << email << " is invalid." << endl;
        }
    }
}

Student Roster::findStudent(int index) {
    return classRosterArray[index];
}
