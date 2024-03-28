#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include "Courses.h"
#include "Teachers.h"
#include "Rooms.h"
#include "Time.h"
#include "Sections.h"

using namespace std;

class Timetable
{
private:
	map<string, map<string, vector<tuple<Courses *, Time *, Rooms *>>>> sectionCourses;

public:
	void buildTimetable()
	{
		Rooms *room1 = new Rooms("4-01", 50);
		Rooms *room2 = new Rooms("4-02", 50);
		Rooms *room3 = new Rooms("4-03", 50);
		Rooms *room4 = new Rooms("4-04", 50);

		Students *student1 = new Students(59, "Hashir", "01-131232-059@bahria.com", "BSE-2A");
		Students *student2 = new Students(15, "Asim", "01-131232-015@bahria.com", "BSE-2A");

		Teachers *teacher1 = new Teachers("Waleed", 201, "Waleed123@gmail.com");
		Teachers *teacher2 = new Teachers("Tamim", 200, "Tamim@gmail.com");
		Teachers *teacher3 = new Teachers("Zubair", 150, "Zubair@gmail.com");

		vector<Time *> times = createTimeSlots();

		// Create sections
		Sections *section1 = new Sections("BSE-2A");
		Sections *section2 = new Sections("BSE-2B");

		// Create courses and assign sections
		Courses *course1 = new Courses(403, "CP", teacher1, room1);
		course1->setAssignedSection(section1);
		course1->addStudent(student1);
		course1->addStudent(student2);
		Courses *course2 = new Courses(404, "OOP", teacher2, room1);
		course2->setAssignedSection(section2);
		course2->addStudent(student1);
		course2->addStudent(student2);
		Courses *course3 = new Courses(405, "LA", teacher3, room1);
		course3->setAssignedSection(section1);

		// Populate timetable with courses, times, and rooms
		sectionCourses["Monday"][section1->getName()].push_back(make_tuple(course1, times[0], room1));
		sectionCourses["Monday"][section2->getName()].push_back(make_tuple(course2, times[1], room3));
		sectionCourses["Tuesday"][section1->getName()].push_back(make_tuple(course3, times[0], room2));
	}

	void teacherTimetable(string T_name)
	{
		buildTimetable();
		bool found = false;
		// Map of teacher -> courses
		map<Teachers *, vector<tuple<Courses *, Time *, Rooms *>>> teacherCourses;

		// Iterate over days
		for (const auto &day : sectionCourses)
		{
			cout << "Day: " << day.first << endl;

			// Iterate over sections for the day
			for (const auto &sectionPair : day.second)
			{
				// Iterate over courses for the section
				for (const auto &courseTimeRoomTuple : sectionPair.second)
				{
					Teachers *teacher = get<0>(courseTimeRoomTuple)->getTeacher();
					teacherCourses[teacher].push_back(courseTimeRoomTuple);
				}
			}

			// Display teacher timetable for the current day
			for (const auto &teacherCoursePair : teacherCourses)
			{
				Teachers *teacher = teacherCoursePair.first;
				vector<tuple<Courses *, Time *, Rooms *>> courses = teacherCoursePair.second;
				if (teacher->getName() == T_name)
				{
					cout << "Teacher: " << teacher->getName() << endl;
					for (const auto &courseTimeRoomTuple : courses)
					{
						Courses *course = get<0>(courseTimeRoomTuple);
						Time *time = get<1>(courseTimeRoomTuple);
						Rooms *room = get<2>(courseTimeRoomTuple);
						cout << "Course: " << course->getCourseName() << "\n Time: " << time->getStartTime() << " - " << time->getEndTime() << "\nRoom: " << room->getRoomNumber() << endl;
					}
				}
				else
				{
					found = true;
				}
				cout << endl;
			}
		}
		if (found)
		{

			cout << "Not Found Teacher with this name" << endl;
		}
		cout << "----------------------------------------------------------------------" << endl;
	}

	void sectionTimetable()
	{
		buildTimetable();
		map<Students *, vector<tuple<Courses *, Time *, Rooms *>>> students;

		// Iterate over days
		for (const auto &day : sectionCourses)
		{
			cout << "Day: " << day.first << endl;
			cout << endl;

			// Iterate over sections for the day
			for (const auto &sectionPair : day.second)
			{
				cout << "Section: " << sectionPair.first << endl;
				// Check if there are any courses for this section
				if (sectionPair.second.empty())
				{
					cout << "No courses for this section." << endl;
				}
				else
				{
					// Iterate over courses for the section
					for (const auto &courseTuple : sectionPair.second)
					{
						Courses *course = get<0>(courseTuple); // Accessing course from tuple
						Time *time = get<1>(courseTuple);	   // Accessing time from tuple
						Rooms *room = get<2>(courseTuple);	   // Accessing room from tuple

						cout << "Course: " << course->getCourseName();
						cout << "\nTime: " << time->getStartTime() << " - " << time->getEndTime() << endl;
					}
					cout << endl;
				}
			}
		}
		cout << "----------------------------------------------------------------------" << endl;
	}
	void studentTimetable(string S_name)
	{
		buildTimetable();

		// Map of student -> courses
		map<Students *, vector<tuple<Courses *, Time *, Rooms *>>> studentCourses;

		// Iterate over days
		for (const auto &day : sectionCourses)
		{
			cout << "Day: " << day.first << endl;

			// Iterate over sections for the day
			for (const auto &sectionPair : day.second)
			{
				// Iterate over courses for the section
				for (const auto &courseTimeRoomTuple : sectionPair.second)
				{
					vector<Students *> enrolledStudents = get<0>(courseTimeRoomTuple)->getEnrolledStudents();
					for (Students *student : enrolledStudents)
					{
						studentCourses[student].push_back(courseTimeRoomTuple);
					}
				}
			}

			// Display student timetable for the current day
			bool found = true;
			for (const auto &studentCoursePair : studentCourses)
			{
				Students *student = studentCoursePair.first;
				vector<tuple<Courses *, Time *, Rooms *>> courses = studentCoursePair.second;
				if (student->getstudentname() == S_name)
				{
					cout << "Student: " << student->getstudentname() << endl;
					for (const auto &courseTimeRoomTuple : courses)
					{
						Courses *course = get<0>(courseTimeRoomTuple);
						Time *time = get<1>(courseTimeRoomTuple);
						Rooms *room = get<2>(courseTimeRoomTuple);
						cout << "Course: " << course->getCourseName() << "\n Time: " << time->getStartTime() << " - " << time->getEndTime() << "\n Room: " << room->getRoomNumber() << endl;
					}
					cout << endl;
				}
				else
				{
					found = false;
				}
			}
			if (!found)
			{
				cout << "Not Found Student with this name";
			}
		}
		cout << "----------------------------------------------------------------------" << endl;
	}

	void queriesTimetable(string queryType)
	{
		buildTimetable();

		if (queryType == "day")
		{
			string day;
			cout << "Enter the day (e.g., Monday, Tuesday): ";
			cin >> day;

			// Check if the day exists in the timetable
			if (sectionCourses.find(day) != sectionCourses.end())
			{
				// Display timetable for the specified day
				cout << "Timetable for " << day << ":" << endl;
				for (const auto &sectionPair : sectionCourses[day])
				{
					cout << "Section: " << sectionPair.first << endl;
					for (const auto &courseTuple : sectionPair.second)
					{
						Courses *course = get<0>(courseTuple);
						Time *time = get<1>(courseTuple);
						Rooms *room = get<2>(courseTuple);
						cout << "Course: " << course->getCourseName() << "\nTime: " << time->getStartTime() << " - " << time->getEndTime() << "\nRoom: " << room->getRoomNumber() << endl;
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No timetable available for the specified day." << endl;
			}
		}
		else if (queryType == "time_and_day")
		{
			string day, startTime;
			cout << "Enter the day (e.g., Monday, Tuesday): ";
			cin >> day;
			cout << "Enter the start time (e.g., 8:30): ";
			cin >> startTime;

			// Check if the day exists in the timetable
			if (sectionCourses.find(day) != sectionCourses.end())
			{
				// Display timetable for the specified day and start time
				cout << "Timetable for " << day << " starting from " << startTime << ":" << endl;
				for (const auto &sectionPair : sectionCourses[day])
				{
					for (const auto &courseTuple : sectionPair.second)
					{
						Time *time = get<1>(courseTuple);
						if (time->getStartTime() == startTime)
						{
							Courses *course = get<0>(courseTuple);
							Rooms *room = get<2>(courseTuple);
							cout << "Section: " << sectionPair.first << endl;
							cout << "Course: " << course->getCourseName() << "\nTime: " << time->getStartTime() << " - " << time->getEndTime() << "\nRoom: " << room->getRoomNumber() << endl;
							cout << endl;
						}
					}
				}
			}
			else
			{
				cout << "No timetable available for the specified day." << endl;
			}
		}
		else
		{
			cout << "Invalid query type." << endl;
		}

		cout << "----------------------------------------------------------------------" << endl;
	}

	vector<Time *> createTimeSlots()
	{
		vector<Time *> times;
		times.push_back(new Time("8:30", "9:30"));
		times.push_back(new Time("9:30", "10:30"));
		times.push_back(new Time("10:30", "11:30"));
		times.push_back(new Time("11:30", "12:30"));
		times.push_back(new Time("12:30", "1:30"));
		times.push_back(new Time("1:30", "2:30"));
		return times;
	}
};
