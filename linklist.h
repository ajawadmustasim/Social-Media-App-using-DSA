#pragma once
#include"node.h"
class linklist
{
private:
	node* head;
	node* tail;
public:
	void insertpost(timelinepost);
	void displayTimeLinePost();
	void removefront();
	void removelast();
	void delpost(timelinepost);
	bool empty();

};

