#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class login
{
	string username;
	string password;
public:
	login()
	{
		username = '/0';
		password = '/0';
	}
	login(string un, string ps)
	{
		this->username = un;
		this->password = ps;
	}
	void setusername(string un)
	{
		username = un;
	}
	void setpassword(string ps)
	{
		this->password = ps;
	}
	string getusername()
	{
		return username;
	}
	string getpassword()
	{
		return password;
	}
	void Registeration(string un, string p)
	{
		ofstream fout("loginDetail.txt", ios::app);
		setusername(un);
		setpassword(p);
		fout << username << "," << password << endl;
	}
	void Log(string un, string p)
	{
		string user;
		string pass;
		ifstream fin("loginDetail.txt", ios::in);
		while (!fin.eof())
		{
			getline(fin, user, ',');
			getline(fin, pass,',');
			cout << un << "->" << user << endl;
			cout << p << "->" << pass << endl;
			if (un == user || p == pass)
			{
				cout << "wellcome" << endl;;
				break;
			}
		}
		fin.close();
	}
};