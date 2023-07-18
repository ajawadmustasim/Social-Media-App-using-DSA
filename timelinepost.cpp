#include "timelinepost.h"
#include <string>

void timelinepost::setpost(string post)
{
	this->post = post;
}
string timelinepost::getpost()
{
	return post;
}
void timelinepost:: displaypost()
{
	cout << getpost() << endl << endl;
}