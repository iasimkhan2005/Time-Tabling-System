#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Students.h"
#include "Teachers.h"
#include "Rooms.h"
#include "Courses.h"
#include "Timetable.h"
#include "TimetableManager.h"
using namespace std;


int main()
{
    char choice;
    Courses course;
    TimetableManager manager;
    ofstream outFile("timetable.txt", ios::app); // Open a file for writing
    if (!outFile.is_open()){
        cerr << "Error opening file!" << endl;
        return 1;
    }

    cout << "TIMETABLE SYSTEM\n";
    cout << "1. Enroll course\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin >> course.courseId;
        cin.ignore();
        getline(cin, course.courseName);
        getline(cin, course.teacher.name);
        cin >> course.dayOfWeek;
        cin >> course.startTime;
        cin >> course.endTime;

        manager.addCourse(course);
        course.writeToFile(outFile);
        outFile.close();
        cout << "course added successfully" << endl;
        break;

     default:
        cout << "....... Invalid Choice! .......\n";
        break;

    } while (true);
}