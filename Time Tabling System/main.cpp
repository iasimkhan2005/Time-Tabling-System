#include <iostream>
#include <vector>
#include <string>
#include "Students.h"
#include "Teachers.h"
#include "Rooms.h"
#include "Courses.h"
#include "Timetable.h"
#include "TimetableManager.h"
using namespace std;

void AdditionMenu()
{
    cout << "\n---------- ADDITTION MENU ----------\n";
    cout << "1. Add Student\n";
    cout << "2. Add Teacher\n";
    cout << "3. Add Room\n";
    cout << "4. Add Course\n";
    cout << "5. Add Timetable\n";
}

void RemoveMenu()
{
    cout << "\n---------- REMOVE MENU ----------\n";
    cout << "1. Remove Student\n";
    cout << "2. Remove Teacher\n";
    cout << "3. Remove Room\n";
    cout << "4. Remove Course\n";
    cout << "5. Remove Timetable\n";
}

void ViewMenu()
{
    cout << "\n---------- VIEW MENU ----------\n";
    cout << "1. View Students\n";
    cout << "2. View Teachers\n";
    cout << "3. View Rooms\n";
    cout << "4. View Courses\n";
    cout << "5. View Timetables\n";
}

int main()
{
    char choice;
    do
    {
        cout << "\n---------- MAIN MENU ----------\n";
        cout << "1. Addition options\n";
        cout << "2. Remove options\n";
        cout << "3. View options\n";
        cout << "X. Exit the program\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            AdditionMenu();
            system("pause");
            break;

        case '2':
            RemoveMenu();
            system("pause");
            break;

        case '3':
            ViewMenu();
            system("pause");
            break;

        case 'X':
        case 'x':
            exit(1); // exits the loop and closes the program
            break;

        default:
            cout << "....... Invalid Choice! .......\n";
            break;
        }

    } while (true);
}