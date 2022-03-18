#pragma once
#include<iostream>
#include <vector>
#include"person.h"
#include"Course.h"
using namespace std;
class student_info : public person
{
    static int ID ;
	int academic_year;
public:
	vector<Course> finished_courses;
	vector<Course> courses_in_progress;
	

public:

	student_info();

	// set functions
	
	void setfinished_courses(Course c);
	void setcourses_in_progress(Course c);
	void setacademic_year(int num);

	// get function
    int getid();
	Course getfinished_courses(int index);
	Course getcourses_in_progress(int index);
	int getacademic_year();
};

