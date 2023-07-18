#include "node.h"
node::node()
{
	next = nullptr;
}
node::node(friendlist obj)
{
	frinedObject = obj;
	left = nullptr;
	right = nullptr;
	height = 1;
}
node::node(timelinepost postObject)
{
	setpost(postObject);
}
void node::setpost(timelinepost obj)
{
	postObject = obj;
}
timelinepost node::getpost()
{
	return postObject;
}
void node::setnext(node* n)
{
	this->next = n;
}
node* node::getnext()
{
	return next;
}