#pragma once
#include <iostream>
#include <vector>
#include <string>
class TimetableManager
{
public:
    Timetable timetable;

    void addCourse(const Courses &course)
    {
        timetable.courses.push_back(course);
    }

    bool isClassAvailable(const string &day, const string &startTime, const string &roomId)
    {
        // Add logic to check if the classroom is available at the given time on the specified day
        // You can use additional data structures to track classroom availability
        return true; // Placeholder, implement actual logic
    }

    void queryTimetable(const string &day, const string &startTime)
    {
        for (const auto &course : timetable.courses)
        {
            if (course.dayOfWeek == day && course.startTime == startTime)
            {
                cout << "Course: " << course.courseName << endl;
                cout << "Teacher: " << course.teacher.name << endl;
                cout << "Room: " << course.roomID << endl;
                return;
            }
        }
        cout << "No course found at " << startTime << " on " << day << endl;
    }
};
