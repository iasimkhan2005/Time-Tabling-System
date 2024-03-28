#include <iostream>
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
            exit(0);

        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (true);
}

int main()
{

    // STUDENTS INFO
    Students student1(59, "Hashir", "01-131232-059@bahria.com", "BSE-2A");
    Students student2(15, "Asim", "01-131232-015@bahria.com", "BSE-2A");

    // TEACHERS INFO
    Teachers *teacher1 = new Teachers("SIR-Tamin", 101, "Tamin123@bahria.com");
    Teachers *teacher2 = new Teachers("SIR-Waleed", 102, "Waleed123@bahria.com");

    // ROOMS INFO
    Rooms room1("4-17", 50);
    Rooms room2("4-18", 50);
    Rooms room3("4-19", 50);

    // COURSES INFO
    Courses course1(131, "OOP", teacher1, &room1);
    Courses course2(232, "OOP - Lab ", teacher2, &room2);

    // REGISTRATION INFO
    /*course1.addStudent(student1);*/
    // course1.addStudent(student2);
    // course2.addStudent(student1);
    // course2.addStudent(student2);

    // MAIN MENU

    menu();
    return 0;
}
