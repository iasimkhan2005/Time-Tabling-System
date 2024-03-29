#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Students.h"
#include "Teachers.h"
#include "Courses.h"
#include "Rooms.h"
#include "Timetable.h"
#include "Sections.h"
#include "Time.h"
using namespace std;
// Functions
void menu()
{
    char choice;
    Timetable timetable;
    do
    {
        system("cls");
        cout << "-------------- Welcome to University Time Tabling System --------------\n";
        cout << "Please select an option from the following list:\n";
        cout << "1. Teacher Wise Timetable.\n";
        cout << "2. Student Wise Timetable.\n";
        cout << "3. Section Wise Timetable.\n";
        cout << "4. Queries Wise Timetable\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        string teacher_name;
        string student_name;
        switch (choice)
        {
        case '1':
            system("cls");
            cout << "Enter the Teacher Name:";
            cin >> teacher_name;
            timetable.teacherTimetable(teacher_name);
            system("pause");
            break;

        case '2':
            system("cls");
            cout << "Enter the Student Name:";
            cin >> student_name;
            timetable.studentTimetable(student_name);
            system("pause");
            break;

        case '3':
            system("cls");
            timetable.sectionTimetable();
            system("pause");
            break;
        case '4':
            system("cls");
            cout << "Select query type:\n";
            cout << "1. Query by day\n";
            cout << "2. Query by day and start time\n";
            cout << "Enter your choice: ";
            char queryChoice;
            cin >> queryChoice;
            if (queryChoice == '1')
            {
                timetable.queriesTimetable("day");
            }
            else if (queryChoice == '2')
            {
                timetable.queriesTimetable("time_and_day");
            }
            else
            {
                cout << "Invalid query type." << endl;
            }
            system("pause");
            break;

        case '5':
            break;

        default:
            cout << "Invalid choice\n";
			system("pause");
            break;
        }
    } while (choice != '5');
}

int main()
{
    // MAIN MENU

    menu();

    Timetable timetable;

    // Write teacher timetable to file
    timetable.writeTeacherTimetableToFile("teacher_timetable.txt");

    // Write student timetable to file
    timetable.writeStudentTimetableToFile("student_timetable.txt");

    // Write section timetable to file
    timetable.writeSectionTimetableToFile("section_timetable.txt");

    cout << "Timetables have been written to respective files." << endl;

    return 0;
}
