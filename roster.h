#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;

class Roster {
private:
    Student* classRosterArray;
    static int nextIndex;

public:
    Roster();
    ~Roster();

    void parse(string data);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age,
             int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printDegreeProgram(DegreeProgram degreeProgram);
    Student findStudent(int index);
};

#endif
