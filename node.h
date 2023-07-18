#pragma once
#include"friendlist.h"
#include"timelinepost.h"
class node
{
private:
	node* next;
public:
	timelinepost postObject;
	node();
	node(timelinepost);
	void setpost(timelinepost);
	timelinepost getpost();
	void setnext(node*);
	node* getnext();
	node* left;
	node* right;
	friendlist frinedObject;
	int height;
	node(friendlist);
};

