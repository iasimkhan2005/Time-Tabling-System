#pragma once
#include<iostream>

using namespace std;

class Rooms
{
private:
	string roomNumber;
	int capacity;
public:
	Rooms(string Room_number, int Room_capacity) : roomNumber(Room_number), capacity(Room_capacity) {};

	
	string getRoomNumber() const {
		return roomNumber;
	}
	
	int getcapacity() const {
		return capacity;
	}
};