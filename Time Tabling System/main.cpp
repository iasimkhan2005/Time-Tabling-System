#include<iostream>
#include<map>
#include<vector>
#include "Students.h"
#include "Teachers.h"
#include "Courses.h"
#include "Rooms.h"
#include "Timetable.h"
#include "Sections.h"
#include "Time.h"
using namespace std;
                                    //Functions
void menu();

int main()
{
	                               
	                              //STUDENTS INFO	                             
	Students student1(59, "Hashir", "01-131232-059@bahria.com", "BSE-2A");
	Students student2(15, "Asim", "01-131232-015@bahria.com", "BSE-2A"); 
	                                
	                                //TEACHERS INFO
	Teachers* teacher1 = new Teachers("SIR-Tamin", 101, "Tamin123@bahria.com");
	Teachers* teacher2 = new Teachers("SIR-Waleed", 102, "Waleed123@bahria.com");
	                                  
	                                 //ROOMS INFO
	Rooms room1("4-17", 50);
	Rooms room2("4-18", 50);
	Rooms room3("4-19", 50);

	                                  //COURSES INFO
    Courses course1(131, "OOP", teacher1, &room1);	
	Courses course2(232, "OOP - Lab ", teacher2, &room2);

	                                 //REGISTRATION INFO
	course1.addStudent(student1);
	course1.addStudent(student2);
	course2.addStudent(student1);
	course2.addStudent(student2);

	                                  // MAIN MENU
	void menu();
	return 0;
}

void menu() {



}