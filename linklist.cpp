#include "linklist.h"

void linklist::insertpost(timelinepost obj)
{
	node* n = new node(obj);
	if (head == nullptr)
	{
		head = n;
	}
	else
	{
		tail->setnext(n);
		tail = tail->getnext();
	}
}
void linklist::displayTimeLinePost()
{
	if (head == nullptr)
	{
		cout << "    No Post     " << endl << endl;
	}
	else
	{
		node* temp = head;
		while (temp != nullptr)
		{
			temp->getpost().displaypost();
			temp = temp->getnext();
		}
	}
}
void linklist::removefront()
{
	if (empty())
	{
		cout << "already empty" << endl;
	}
	else
	{
		node* temp = head;
		head = head->getnext();
		delete temp;
	}
}
void linklist::removelast()
{
	if (!empty())
	{
		if (head == tail)
		{
			head = nullptr;
			delete tail;
			tail = nullptr;
		}
		else
		{
			node* temp = head;
			while (temp->getnext() != tail)
			{
				temp = temp->getnext();
			}
			tail = temp;
			temp = temp->getnext();
			delete temp;
			tail->setnext(nullptr);
		}
	}
}
bool linklist::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

void linklist::delpost(timelinepost obj)
{
	if (head == tail)
	{
		if(head->postObject.getpost() == obj.getpost())
		{
			removefront();
		}
	}
	else if (tail->postObject.getpost() == obj.getpost())
	{
		removelast();
	}
	else
	{
		node* temp = head;
		node* pre = nullptr;
		while (temp != nullptr)
		{
			if (temp->postObject.getpost() == obj.getpost())
			{
				pre->setnext(temp->getnext());
				delete temp;
			}
			pre = temp;
			temp = temp->getnext();
		}
	}
}