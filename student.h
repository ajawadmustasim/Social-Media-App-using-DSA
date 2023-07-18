#pragma once
#include"AVL.h"
#include"linklist.h"
#include "Heap.h"

class student
{
private:
	string name;
	string id;
	string password;
	int year;
public:
	void setname(string);
	void setid(string);
	void setpassword(string);
	void setyear(int);
	int getyear();
	string getname();
	string getpassword();
	string getid();
	linklist postobject;
	AVL fobject;
	Heap hobject;

};

