#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Courses
{
public:
    string courseId;
    string courseName;
    Teachers teacher;
    string roomID;
    string dayOfWeek;
    string startTime;
    string endTime;

    // Function to write course details to a file
    void writeToFile(ofstream& file) const
    {
        file << "Course ID: " << courseId << endl;
        file << "Course Name: " << courseName << endl;
        file << "Teacher: " << teacher.name << endl;
        file << "Day: " << dayOfWeek << endl;
        file << "Time: " << startTime << " - " << endTime << endl;
        file << "------------------------\n";
    }
};
