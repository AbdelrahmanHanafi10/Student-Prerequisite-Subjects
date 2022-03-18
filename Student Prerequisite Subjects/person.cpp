#include "person.h"


void person::setname(string name)
{
	this->name = name;
}

void person::setpassword(string password)
{
	this->password = password;
}

string person::getname()
{
	return name;
}

string person::getpassword()
{
	return password;
}
