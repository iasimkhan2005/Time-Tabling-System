#pragma once
class Time
{
private:
	string Start_Time, End_Time;
public:
	Time() {};
	Time(string start, string end) :Start_Time(start), End_Time(end) {};
	string getStartTime() {
		return Start_Time; 
	}
	string getEndTime() { 
		return End_Time; 
	}
};
