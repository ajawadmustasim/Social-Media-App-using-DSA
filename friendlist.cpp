#include "friendlist.h"
#include <string>

void friendlist::setName(string name)
{
	this->name = name;
}
void friendlist::setPhone(int phone)
{
	this->phone = phone;
}
void friendlist::setEmail(string email)
{
	this->email = email;
}
string friendlist::getName()
{
	return name;
}
int friendlist::getPhone()
{
	return  phone;
}
string friendlist::getEmail()
{
	return email;
}
void friendlist::display()
{
	cout << "*******************************************************" << endl;
	cout << "Name  : " << getName() << endl;
	cout << "phone : " << getPhone() << endl;
	cout << "Email : " << getEmail() << endl;
	cout << "*******************************************************" << endl << endl << endl;

}