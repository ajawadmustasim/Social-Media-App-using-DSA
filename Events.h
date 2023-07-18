#pragma once

#include "Date.h"
#include "Time.h"

class Events
{
	string info;
	Date date;
	Time time;
public:
	Events()
	{
		info = "new event";
	}
	void setInfo(string info)
	{
		this->info = info;
	}
	void setDate(Date date)
	{
		this->date = date;
	}
	void setTime(Time time)
	{
		this->time = time;
	}
	string getInfo()
	{
		return info;
	}
	Date getDate()
	{
		return date;
	}
	Time getTime()
	{
		return time;
	}
};
