#pragma once
#include"person.h"
#include"student_list.h"
#include<string>
class Admin : public person
{
	string admin_name[2] = { "admin1","admin2" };
	string admin_pass[2] = { "123a","456b" };

public:
	student_info addstudent(vector<Course> c);
	Course addcourse();
	void view_students_in_a_specific_course(vector<student_info> s);
	void view_List_of_all_courses_in_aspecific_student(vector<student_info> s);
	void  edit_data_of_courses(vector<Course>&);  // edit password
	bool admin_login(string name, string pass);

};
