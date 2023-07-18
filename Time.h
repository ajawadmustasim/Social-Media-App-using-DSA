#pragma once

#include <iostream>
#include <string>
using namespace std;

class Time
{
	int hour;
	int minute;
public:
	Time()
	{
		hour = 0;
		minute = 0;
	}
	Time(int hour, int minute)
	{
		setHour(hour);
		setMinute(minute);
	}
	void setHour(int hour)
	{
		if (hour > 0 && hour < 24)
			this->hour = hour;
		else
			this->hour = 0;
	}
	void setMinute(int minute)
	{
		if (minute > 0 && minute < 60)
			this->minute = minute;
		else
			this->minute = 0;
	}
	int getHour()
	{
		return hour;
	}
	int getMinute()
	{
		return minute;
	}

	inline bool operator<(Time &t)
	{
		if (hour < t.hour)
			return true;

		else if (hour > t.hour)
			return false;

		else
		{
			if (minute < t.minute)
				return true;

			else
				return false;
		}
	}

	friend istream& operator>>(istream& in, Time& r);
	friend ostream& operator<<(ostream& out, const Time& r);
};

inline ostream& operator<<(ostream& out, const Time& t)
{
	out << t.hour << ":" << t.minute << endl;
	return out;
}

inline istream& operator>>(istream& in, Time& t)
{
	cout << "Enter Time" << endl;

	cout << "Enter hour : ";
	in >> t.hour;
	if (t.hour < 0 || t.hour > 23)
		t.hour = 0;

	cout << "Enter minute : ";
	in >> t.minute;
	if (t.minute < 0 || t.minute > 59)
		t.minute = 0;

	return in;
}