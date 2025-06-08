#include "student.h"
#include <iostream>
using namespace std;

void Student::print() {
    cout<<student_id<<"\t";
    cout<<"First Name: " << first_name << "\t";
    cout<<"Last Name: "<< last_name<<"\t";
    cout<<"Age: "<<age<<"\t";
    cout<<"Days in Course: {"<<daysToComplete[0]<<","
    <<daysToComplete[1]<< "," <<daysToComplete[2]<< ","<<"}"<<"\t";
    cout << "DegreeProgram: " << printDegree(this->getDegreeProgram()) << endl;
}
string Student::printDegree(DegreeProgram dp) {
    if (dp == SECURITY) {
        return "Security";
    } else if (dp == NETWORK) {
        return "Network";
    } else if(dp == SOFTWARE){
        return "Software";
    } else {
        return "Unknown";
    }
}