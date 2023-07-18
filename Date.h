#pragma once

#include <iostream>
#include <string>
using namespace std;

class Date
{
	int year;
	int month;
	int day;
public:
	Date()
	{
		year = 2022;
		month = 1;
		day = 1;
	}
	Date(int year, int month, int day)
	{
		setYear(year);
		setMonth(month);
		setDay(day);
	}
	void setYear(int year)
	{
		if (year > 0)
			this->year = year;
		else
			this->year = 2022;
	}
	void setMonth(int month)
	{
		if (month > 0 && month < 13)
			this->month = month;
		else
			this->month = 1;
	}
	void setDay(int day)
	{
		if (day>0 && day < 32)
			this->day = day;
		else
			this->day = 1;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	inline bool operator==(Date &d)
	{
		if (day == d.day && month == d.month && year == d.year)
			return true;
		return false;
	}
	inline bool operator<(Date &d)
	{
		if (year < d.year)
			return true;

		else if (year > d.year)
			return false;

		else
		{
			if (month < d.month)
				return true;

			else if (month > d.month)
				return false;

			else
			{
				if (day < d.day)
					return true;

				else
					return false;
			}
		}
	}

	friend istream& operator>>(istream& in, Date& r);
	friend ostream& operator<<(ostream& out, const Date& r);
};

inline istream& operator>>(istream& in, Date& d)
{
	cout << "Enter Date" << endl;

	cout << "Enter year : ";
	in >> d.year;
	if (d.year < 1)
		d.year = 2022;

	cout << "Enter month : ";
	in >> d.month;
	if (d.month < 1 || d.month > 12)
		d.month = 1;

	cout << "Enter day : ";
	in >> d.day;
	if (d.day < 1 || d.day > 31)
		d.day = 1;
	

return in;
}

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d.day << "-" << d.month << "-" << d.year << endl;
	return out;
}