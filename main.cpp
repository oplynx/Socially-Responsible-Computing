#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

int main() {
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,John,Doe,johndoe@weirdemail.com,15,20,30,40,SOFTWARE"
    };

    cout << "CS216 - Project\n";

    Roster* classRoster = new Roster();

    for (int i = 0; i < 5; ++i) {
        classRoster->parse(studentData[i]);
    }

    classRoster->printAll();
    cout << "Printing Invalid Emails " << endl;
    classRoster->printInvalidEmails();
    cout << "Printing Average days in course for Students " << endl;
    for (int i = 0; i<5; i++) {
        Student s = classRoster -> findStudent(i);
        classRoster->printAverageDaysInCourse(s.getStudentID());
    }
    cout << "Degree Program" << endl;
    classRoster -> printDegreeProgram(DegreeProgram::SOFTWARE);// SECURITY OR NETWORK

    cout << "Removing A3" << endl;
    classRoster -> remove("A3");
    cout << "Printing again!" << endl;
    classRoster->printAll();

    delete classRoster;
    return 0;
}
