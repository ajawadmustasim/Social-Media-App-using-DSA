//#include<iostream>
#include<fstream>
#include<string>
#include"login.h"
#include"hash.h"
#include"friendlist.h"
#include"timelinepost.h"
#include"student.h"
#include "Heap.h"
//using namespace std;

int main()
{
	string password;
	string username;
	int operation;
	login logObject;

	timelinepost obj;
	student studentobject;
	friendlist fobj;
	int instruction = 0;
	
	while (1)
	{
	cout << "*****************MAIN MANU******************" << endl;
	cout << "1-> LOGIN " << endl;
	cout << "2-> Register " << endl;
	cout << "3-> EXIT" << endl;

		cout << "->";
		cin >> operation;
		if (operation == 1)
		{
			cin.ignore();
			cout << "what is the user name" << endl;
			cin >> username;
			cout << "what is the password" << endl;
			cin >> password;
			logObject.Log(username, password);
			studentobject.setname(username);
			studentobject.setpassword(password);
			while (1)
			{

				cout << endl << "Press 1 to post on timeline!" << endl;
				cout << "Press 2 add event to list!" << endl;
				cout << "Press 3 to view list of friends" << endl;
				cout << "Press 4 to add/remove friend" << endl;
				cout << "Press 5 to logout" << endl;
				cout << "Enter your instruction : ";
				cin >> instruction;
				if (instruction == 1)
				{
					string post;
					cout << endl << "Press 1 to type post " << endl;
					cout << "Press other key to cancel" << endl;
					cout << "Enter your instruction : ";
					cin >> instruction;
					if (instruction == 1)
					{
						cout << "Type your post : ";
						cin >> post;
						obj.setpost(post);
						studentobject.postobject.insertpost(obj);
					}
				}
				else if (instruction == 2)
				{
				Date d1, d2;
				Time t1, t2;
				Events e1, e2;
				string info;

				d1.setDay(1);
				d1.setMonth(1);
				d1.setYear(2023);
				t1.setHour(0);
				t2.setMinute(0);

				e1.setInfo("New year celebration!");
				e1.setDate(d1);
				e1.setTime(t1);

				d2.setDay(10);
				d2.setMonth(11);
				d2.setYear(2022);
				t2.setHour(17);
				t2.setMinute(30);

				e1.setInfo("Takra!");
				e1.setDate(d2);
				e1.setTime(t2);

				cout << endl << "Event 1 = " << e1.getInfo() << endl;
				cout << "Date = " << d1;
				cout << "Time = " << t1 << endl;

				cout << endl << "Event 2 = " << e2.getInfo() << endl;
				cout << "Date = " << d2;
				cout << "Time = " << t2 << endl;

				cout << endl << "Press 1 to add event 1 or press 2 to add event 2 or press 3 to enter both or press any key to enter new event" << endl;
				cout << "Enter your instruction : ";
				cin >> instruction;

				if (instruction == 1)
				{
					studentobject.hobject.insert(e1);
				}
				else if (instruction == 2)
				{
					studentobject.hobject.insert(e2);
				}
				else if (instruction == 3)
				{
					studentobject.hobject.insert(e1);
					studentobject.hobject.insert(e2);
				}
				else
				{
				cout << "Enter event info you want to enter : ";
					cin >> info;
					cin >> d1;
					cin >> t1;

					e1.setInfo(info);
					e1.setDate(d1);
					e1.setTime(t1);

					studentobject.hobject.insert(e1);


				}
				cout << "Event(s) successfully added in your list!" << endl << endl;

				}
				else if (instruction == 3)
				{
					studentobject.fobject.printTree(studentobject.fobject.root);
				}
				else if (instruction == 4)
				{
					string name;
					int phone;
					string email;
					cout << "what is the name " << endl;
					cin >> name;
					cout << "what is the phone " << endl;
					cin >> phone;
					cout << "what is the email" << endl;
					cin >> email;
					fobj.setName(name);
					fobj.setEmail(email);
					fobj.setPhone(phone);
					studentobject.fobject.insert(studentobject.fobject.root, fobj);

				}
				else if (instruction == 5)
				{
					cout << endl << "logging out!" << endl << endl;
					break;
				}
				else
				{
					cout << endl << "Invalid Input! Enter instruction again!" << endl;
				}
			}

		}
		else if (operation == 2)
		{
			cin.ignore();
			cout << "what is the user name" << endl;
			cin >> username;
			cout << "what is the password" << endl;
			cin >> password;
			logObject.Registeration(username, password);
		}
		else if(operation==3)
		{
			exit(1);
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}

}