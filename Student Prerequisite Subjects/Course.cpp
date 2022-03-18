#include "Course.h"

Course::Course()
{
}

void Course::setname(string name)
{
	this->name = name;
}

void Course::setcode(string code)
{
	this->code = code;
}

void Course::setnum_of_student(int num)
{
	this->num_of_student = num;
}

void Course::setrequired(string req)
{
	required.push_back(req);
}

void Course::sethours(int hours)
{
	this->hours = hours;
}

string Course::getname()
{
	return name;
}

string Course::getcode()
{
	return code;
}

int Course::getnum_of_student()
{
	return num_of_student;
}

string Course::getrequired(int index)
{
	return required[index];
}

int Course::gethours()
{
	return hours;
}
