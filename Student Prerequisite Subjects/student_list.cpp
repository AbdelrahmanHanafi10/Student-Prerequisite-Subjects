#include<iostream>
#include<string>
#include<vector>
#include "student_list.h"
using namespace std;


int student_info::ID = 0;

student_info::student_info():academic_year(0)
{
	ID++;
}

void student_info::setfinished_courses(Course c)
{
	this->finished_courses.push_back(c);
}

void student_info::setcourses_in_progress(Course c)
{
	this->courses_in_progress.push_back(c);
}

void student_info::setacademic_year(int num)
{
	this->academic_year = num;
}



int student_info::getid()
{
	return ID;
}

Course student_info::getfinished_courses(int index)
{
	return finished_courses[index];
}

Course student_info::getcourses_in_progress(int index)
{
	return courses_in_progress[index];
}



int student_info::getacademic_year()
{
	return academic_year;
}
