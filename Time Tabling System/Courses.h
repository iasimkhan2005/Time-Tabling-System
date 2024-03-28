#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Teachers.h"
#include "Rooms.h"
#include "Sections.h"
#include "Time.h"
#include "Students.h"
// class Students; // Forward declaration of Student class

using namespace std;

class Courses
{
private:
    int courseCode;
    int studentCode;
    string courseName;
    Rooms *assignedRoom;
    Teachers *teacher;
	Students* student;
    Sections *assignedSection;
    Time *assignedTime;
    map<int, string> student_data;

public:
    vector<Students *> enrolledStudents;
	Courses();
    Courses(int courseCode, const string &courseName, Teachers *teacher, Rooms *assignedRoom) : courseCode(courseCode), courseName(courseName), teacher(teacher), assignedRoom(assignedRoom), assignedSection(nullptr), assignedTime(nullptr) {}

     void addStudent(Students* student)
     {
		 enrolledStudents.push_back(student);
     }
    // void removeStudent(Students student)
    // {
    //     student_data[student.getStudentID()].erase();
    // }

    string getCourseName()
    {
        return courseName;
    }

    Teachers* getTeacher() const
    {
        return teacher;
    }
    /*Rooms *getAssignedRoom() const;
    Sections *getAssignedSection() const;
    Time *getAssignedTime() const;*/
    void setAssignedSection(Sections* section) {
		assignedSection = section;
    }

    vector<Students*> getEnrolledStudents() const
    {
        return enrolledStudents;
    }
};