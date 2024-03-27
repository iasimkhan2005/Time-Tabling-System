#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Students.h"
#include "Teachers.h"
#include "Rooms.h"
#include "Courses.h"
#include "Timetable.h"
#include "TimetableManager.h"
using namespace std;

Courses parseLine(string& line)
{
    Courses course;
    stringstream ss(line);
    string temp;

    ss >> temp >> course.courseId;
    ss >> temp >> course.courseName;
    getline(ss, course.teacher.name, '\n');
    ss >> temp >> course.dayOfWeek;
    ss >> temp >> course.startTime;

    return course;
}

int main()
{
    char choice;
    Courses course;
    TimetableManager manager;
    ofstream outFile("timetable.txt", ios::app); // Open a file for writing
    if (!outFile.is_open()) {
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

    }

    ifstream inFile("timetable.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<Courses> courses;
    string line;

    while (getline(inFile, line)) {
        Courses course = parseLine(line);
        courses.push_back(course);
    }
    inFile.close();

    string search;

    cout << "Enter anything to search: ";
    cin.ignore();
    getline(cin, search);

    bool found = false;
    for (const Courses& course : courses) {
        if (course.dayOfWeek == search || course.courseName == search || course.teacher.name == search) {
            cout << "Course code: " << course.courseId << endl;
            cout << "Course name: " << course.courseName << endl;
            cout << "Teacher: " << course.teacher.name << endl;
            cout << "Day: " << course.dayOfWeek << endl;
            cout << "Start time: " << course.startTime << endl;
            cout << "End time: " << course.endTime << endl;
            found = true;
        }
    }

    return 0;
}