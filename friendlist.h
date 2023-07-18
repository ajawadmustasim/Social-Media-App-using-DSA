#pragma once
#include<iostream>
using namespace std;
class friendlist
{
private:
	string name;
	int phone;
	string email;
public:
	void setName(string);
	void setPhone(int);
	void setEmail(string);
	string getName();
	int getPhone();
	string getEmail();
	void display();
};

