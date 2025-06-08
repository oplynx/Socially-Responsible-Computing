
#ifndef degree_h
#define degree_h
#include <string>
#include "degree.h"
using namespace std;

class Student {

    private:
        string student_id;
        string first_name;
        string last_name;
        string emailAddress;
        int age;
        int daysToComplete[3];
        DegreeProgram degreeProgram;
    public:
        // Default values
        Student(){
            student_id = "Invalid";
            first_name = "Invalid";
            last_name = "Invalid";
            emailAddress = "Invalid";
            age = 0;
            daysToComplete[0] = -1;
            daysToComplete[1] = -1;
            daysToComplete[2] = -1;
            degreeProgram = DegreeProgram::SOFTWARE;
        }

        Student(string sId, string fn, string ln, string ea, int a, int * dtc, DegreeProgram dp) {
            student_id = sId;
            first_name = fn;
            last_name = ln;
            emailAddress = ea;
            age = a;
            daysToComplete[0] = dtc[0];
            daysToComplete[1] = dtc[1];
            daysToComplete[2] = dtc[2];
            degreeProgram = dp;
        }

        // Accessors
        string getStudentID() {
            return student_id;
        }

        string getFirstName() {
            return first_name;
        }

        string getLastName() {
            return last_name;
        }

        string getEmailAddress() {
            return emailAddress;
        }

        int getAge() {
            return age;
        }

        int * getDaysToComplete() {
            return daysToComplete;
        }

        DegreeProgram getDegreeProgram() {
            return degreeProgram;
        }

        // Mutators

        void setStudentId(string sID) {
            student_id = sID;
        }

        void setFirstName(string fn) {
            first_name = fn;
        }

        void setLastName(string ln) {
            last_name = ln;
        }

        void setEmailAdress(string emailAdress) {
            this->emailAddress = emailAdress;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setDaysToComplete(int * dtc) {
            daysToComplete[0] = dtc[0];
            daysToComplete[1] = dtc[1];
            daysToComplete[2] = dtc[2];
        }

        void setDegreeProgram(DegreeProgram degreeProgram) {
            this->degreeProgram = degreeProgram;
        }
        
        void print();
        string printDegree(DegreeProgram dp);
};


#endif