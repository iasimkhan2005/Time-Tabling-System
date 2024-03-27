#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Courses.h"
#include "Teachers.h"
#include "Rooms.h"
#include "Time.h"
#include "Sections.h"

using namespace std;

class Timetable {
private:
    map<std::string, std::map<std::string, std::vector<std::tuple<Courses*, Time*, Rooms*>>>> sectionCourses;

public:
    void buildTimetable() {
        Rooms* room1 = new Rooms("4-01", 50);
        Rooms* room2 = new Rooms("4-02", 50);
        Rooms* room3 = new Rooms("4-03", 50);
        Rooms* room4 = new Rooms("4-04", 50);

        Teachers* teacher1 = new Teachers("Waleed", 201, "Waleed123@gmail.com");
        Teachers* teacher2 = new Teachers("Tamim", 200, "Tamim@gmail.com");
        Teachers* teacher3 = new Teachers("Ds wali mam", 150, "ds@gmail.com");

        vector<Time*> times = createTimeSlots();

        // Create sections
        Sections* section1 = new Sections("SE-01");
        Sections* section2 = new Sections("SE-02");

        // Create courses and assign sections
        Courses* course1 = new Courses(403, "OOP", teacher1, room1);
        course1->setAssignedSection(section1);
        Courses* course2 = new Courses(404, "DS", teacher2, room1);
        course2->setAssignedSection(section2);
        Courses* course3 = new Courses(405, "Algorithms", teacher3, room1);
        course3->setAssignedSection(section1);

        // Populate timetable with courses, times, and rooms
        sectionCourses["Monday"][section1->getName()].push_back(make_tuple(course1, times[0], room1));
        sectionCourses["Monday"][section2->getName()].push_back(make_tuple(course2, times[1], room3));
        sectionCourses["Tuesday"][section1->getName()].push_back(make_tuple(course3, times[0], room2));
    }

    void teacherTimetable() {
        buildTimetable();

        // Map of teacher -> courses
        map<Teachers*, vector<tuple<Courses*, Time*, Rooms*>>> teacherCourses;

        // Iterate over days
        for (const auto& day : sectionCourses) {
            cout << "Day: " << day.first << endl;

            // Iterate over sections for the day
            for (const auto& sectionPair : day.second) {
                // Iterate over courses for the section
                for (const auto& courseTimeRoomTuple : sectionPair.second) {
                    Teachers* teacher =& get<0>(courseTimeRoomTuple)->getTeacher();
                    teacherCourses[teacher].push_back(courseTimeRoomTuple);
                }
            }

            // Display teacher timetable for the current day
            for (const auto& teacherCoursePair : teacherCourses) {
                Teachers* teacher = teacherCoursePair.first;
                vector<tuple<Courses*, Time*, Rooms*>> courses = teacherCoursePair.second;
                if (teacher->getName() == "Tamim") {
                    cout << "Teacher: " << teacher->getName() << endl;
                    for (const auto& courseTimeRoomTuple : courses) {
                        Courses* course = get<0>(courseTimeRoomTuple);
                        Time* time = get<1>(courseTimeRoomTuple);
                        Rooms* room = get<2>(courseTimeRoomTuple);
                        cout << "Course: " << course->getCourseName() << ", Time: " << time->getStartTime() << " - " << time->getEndTime() << ", Room: " << room->getRoomNumber() << endl;
                    }
                }
                cout << endl;
            }
        }
    }


    void sectionTimetable() {
        //buildTimetable();

        //// Iterate over days
        //for (const auto& day : sectionCourses) {
        //    cout << "Day: " << day.first << endl;

        //    // Iterate over sections for the day
        //    for (const auto& sectionPair : day.second) {
        //        cout << "Section: " << sectionPair.first << endl;

        //        // Check if there are any courses for this section
        //        if (sectionPair.second.empty()) {
        //            cout << "No courses for this section." << endl;
        //        }
        //        else {
        //            // Iterate over courses for the section
        //            for (const auto& courseTimePair : sectionPair.second) {
        //                cout << "Course: " << courseTimePair.first->getCourseName();
        //                cout << ", Time: " << courseTimePair.second->getStartTime() << " - " << courseTimePair.second->getEndTime() << endl;
        //            }
        //        }
        //    }
        //}
    }

    vector<Time*> createTimeSlots() {
        vector<Time*> times;
        times.push_back(new Time("8:30", "9:30"));
        times.push_back(new Time("9:30", "10:30"));
        times.push_back(new Time("10:30", "11:30"));
        times.push_back(new Time("11:30", "12:30"));
        times.push_back(new Time("12:30", "1:30"));
        times.push_back(new Time("1:30", "2:30"));
        return times;
    }
};
