#include "AVL.h"

AVL::AVL()
{
	root = nullptr;
}
int AVL::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int AVL::gethight(node* temp)
{
	if (temp == nullptr)
	{
		return 0;
	}
	return temp->height;
}
int AVL::balancefactor(node* temp)
{
	if (temp == nullptr)
	{
		return 0;
	}
	return gethight(temp->left) - gethight(temp->right);
}
node* AVL::leftrotation(node* x)
{
	node* y = x->right;
	node* t2 = y->left;
	y->left = x;
	t2 = x->right;
	y->height = max(gethight(y->left), gethight(y->right)) + 1;
	x->height = max(gethight(x->left), gethight(x->right)) + 1;
	return y;
}
node* AVL::rightrotation(node* y)
{
	node* x = y->left;
	node* t2 = x->right;
	x->right = y;
	t2 = y->left;
	y->height = max(gethight(y->left), gethight(y->right)) + 1;
	x->height = max(gethight(x->left), gethight(x->right)) + 1;
	return x;
}
node* AVL::insert(node* temp,friendlist key)
{
	if (temp == nullptr)
	{
		return new node(key);
	}
	else if (temp->frinedObject.getName() < key.getName())
	{
		temp->right = insert(temp->right, key);
	}
	else if (temp->frinedObject.getName() > key.getName())
	{
		temp->left = insert(temp->left, key);
	}
	else
	{
		return temp;
	}
	temp->height = max(gethight(temp->left), gethight(temp->right)) + 1;
	int bf = balancefactor(temp);
	if (bf == 2)
	{
		if (key.getName() < temp->left->frinedObject.getName())
		{
			return rightrotation(temp);
		}
		else
		{
			temp->left = leftrotation(temp->left);
			return rightrotation(temp);
		}
	}
	else if (bf == -2)
	{
		if (key.getName() > temp->right->frinedObject.getName())
		{
			return leftrotation(temp);
		}
		else
		{
			temp->right = rightrotation(temp->right);
			return leftrotation(temp);
		}
	}
	return temp;
}
void AVL::printTree(node* root) {
	if (root != nullptr) {
		printTree(root->left);
		root->frinedObject.display();
		printTree(root->right);
	}
}