#pragma once
#include "Events.h"

class Heap
{
	int size;
	int current;
	Events* data;
public:
	Heap()
	{
		data = NULL;
		size = 0;
		current = 0;
	}
	Heap(int size)
	{
		this->size = size;
		data = new Events[size];
		current = 0;
	}
	int getTotal()
	{
		return current;
	}
	void swap(Events &a, Events &b)
	{
		Events temp = a;
		a = b;
		b = temp;
	}
	void insert(Events data)
	{
		if (current < size)
		{
			this->data[current] = data;
			int temp = current;
			while (current>0 && this->data[temp].getDate() < this->data[((temp - 1) / 2)].getDate())
			{
				if (this->data[temp].getDate() == this->data[((temp - 1) / 2)].getDate())
				{
					if (this->data[temp].getTime() < this->data[((temp - 1) / 2)].getTime())
					{
						swap(this->data[temp], this->data[((temp - 1) / 2)]);
						temp = (temp - 1) / 2;
					}
				}
				else
				{
					swap(this->data[temp], this->data[((temp - 1) / 2)]);
					temp = (temp - 1) / 2;
				}
			}
			current++;
		}
	}
	void inorder(int i)
	{
		if (i < current)
		{
			inorder(i * 2 + 1);
			cout << "Event = " << data[i].getInfo() << endl;
			cout << "Date = " << data[i].getDate();
			cout << "Time = " << data[i].getTime() << endl;
			inorder(i * 2 + 2);
		}
	}
	int leftChild(int i)
	{
		if ((i * 2 + 1) < current)
		{
			return i * 2 + 1;
		}
		return -1;
	}
	int rightChild(int i)
	{
		if ((i * 2 + 2) < current)
		{
			return i * 2 + 2;
		}
		return -1;
	}
	int min(int a, int b)
	{
		if (data[a].getDate() < data[b].getDate())
			return a;

		else if (data[a].getDate() == data[b].getDate())
		{
			if (data[a].getTime() < data[b].getTime())
				return a;
		}

		return b;
	}
	Events deleteData()
	{
		Events temp = data[0];
		data[0] = data[current - 1];
		current--;

		int i = 0;

		while (i < current)
		{
			int leftIndex = leftChild(i);
			int rightIndex = rightChild(i);
			if (leftIndex != -1 && rightIndex != -1)
			{
				int smallest = min(leftIndex, rightIndex);
				if (data[smallest].getDate() < data[i].getDate())
				{
					if (data[smallest].getDate() == data[i].getDate())
					{
						if (data[smallest].getTime() < data[i].getTime())
						{
							swap(data[smallest], data[i]);
							i = smallest;
						}
					}
					else
					{
						swap(data[smallest], data[i]);
						i = smallest;
					}
				}
			}
			else if (leftIndex != -1 && rightIndex == -1)
			{
				swap(data[i * 2 + 1], data[i]);
				i = i * 2 + 1;
			}
			else
			{
				break;
			}
		}
		return temp;
	}
};