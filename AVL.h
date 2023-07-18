#pragma once
#include"node.h"
class AVL
{
public:
	node* root;
	AVL();
	int max(int a, int b);
	int gethight(node* temp);
	int balancefactor(node* temp);
	node* leftrotation(node* x);
	node* rightrotation(node* y);
	node* insert(node*, friendlist);
	void printTree(node* root);
};

