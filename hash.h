#pragma once
#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node*next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class hashtable
{
	Node**arr;
	int size;
public:
	hashtable()
	{
		arr = NULL;
		size = 0;
	}
	hashtable(int size)
	{
		this->arr = new Node*[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = NULL;
		}
		this->size = size;
	}
	int hash(int data)
	{
		int key = data;
		return key;
	}
	void insert(int data)
	{
		int key = hash(data);
		Node*temp = arr[key];
		if (temp->next = NULL)
		{
			arr[key] = new Node(data);
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new Node(data);
		}

	}
	bool search(int data)
	{
		if (arr == NULL)
		{
			cerr << "empty\n";
		}
		else
		{
			int key = hash(data);
			Node*temp = arr[key];
			if (temp == NULL)
			{
				cout << "data not found";
				return false;
			}
			else
			{
				while (temp != NULL)
				{
					if (temp->data = data)
					{
						cout << data << "found\n";
						return true;
					}
					temp = temp->next;
				}
			}
			return false;
		}
	}
	void display()
	{
		if (arr == NULL)
		{
			cerr << "empty";
		}
		else
		{
			for (int i = 0; i <= size; i++)
			{
				Node*temp = arr[i];
				while (temp->data != NULL)
				{
					cout << temp->data << "\n";
					temp = temp->next;
				}
				cout << "\n";
			}
		}
	}
};