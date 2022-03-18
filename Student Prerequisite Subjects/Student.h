#pragma once
#include<iostream>
#include"person.h"
#include"Course.h"
#include "student_list.h"
using namespace std;

class student : public Course
{

public:
	student();
	//bool open(string, string,vector<student_info>);  //  log in
	bool open(string, string, vector<student_info>);  //  log in

	void view_all_courses(int, vector<student_info>);
	void  edit_data(vector<student_info>&, string pass, int index);  // edit password
	void view_list_of_all_available_courses(vector<Course> c);  // after class admin
	void view_details_of_a_specific_course(vector<Course>&); // after class courses
	void registerr_for_course(vector<Course>& , vector<student_info>& , int );        //after class admin & courses
};