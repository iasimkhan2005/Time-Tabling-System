#pragma once
#include <string>
#include <vector>
#include <algorithm> 
#include "Students.h" 
class Students;
using namespace std;
class Sections {
private:
    string name;
    vector<Students*> students;

public:
    Sections(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    void addStudent(Students* student) {
        students.push_back(student);
    }

    void removeStudent(Students* student) {
        auto it = find(students.begin(), students.end(), student);
        if (it != students.end()) {
            students.erase(it);
        }
    }

    const  vector<Students*>& getStudents() const {
        return students;
    }
};
