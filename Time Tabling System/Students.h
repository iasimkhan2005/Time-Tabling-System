#pragma once
#include <string>
#include <vector>
#include "Courses.h"

using namespace std;
class Students
{
private:
	int student_ID;
	string Student_name, Student_email, Student_section;


public:
	vector<Courses*>coursesEnrolled;
	Students(int ID, string name, string email, string section) :student_ID(ID), Student_name(name), Student_email(email), Student_section(section) {};
	
	string getstudentname() {
		return Student_name;
	}
	int getStudentID() { 
		return student_ID; 
	}
	string getsection()const {
		return Student_section;
	}
};