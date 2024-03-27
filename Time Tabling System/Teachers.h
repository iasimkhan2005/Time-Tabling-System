#pragma once
#include <string>
#include <vector>
class Courses;
using namespace std;

class Teachers
{
private:
	int teacher_ID;
	string teacher_name, teacher_email;
	vector<Courses*> coursesTaught;
public:
	Teachers(std::string name, int ID, std::string email) :teacher_name(name), teacher_ID(ID), teacher_email(email) {};


	string getName()
	{
		return teacher_name;
	}
};