#include "student.h"

void student::setname(string n)
{
	name = n;
}
void student::setid(string i)
{
	id = i;
}
void student::setpassword(string p)
{
	password = p;
}
void student::setyear(int y)
{
	year = y;
}
int student::getyear()
{
	return year;
}
string student::getname()
{
	return name;
}
string student::getpassword()
{
	return password;
}
string student::getid()
{
	return id;
}