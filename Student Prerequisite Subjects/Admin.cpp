#include<string>
#include<vector>
#include "Admin.h"
#include"student_list.h"
#include<iostream>
using namespace std;
student_info Admin::addstudent(vector<Course> c)
{
	system("CLS");  // clear the console

	cout << "\n\n\t\t\t\t\t ADD STUDENT \n\n\n\n";
	// I make variable (student_info s) to store student data and return it 
	student_info s;

	// variables to store data and put it in s
	string name;
	string pass;
	int id;
	string finished;
	int academic_year;

	// to check if he/she has a finished course
	bool check = true;//modified
	int checknum = 0;//modified

	// get student data
	cout << "\t Please enter the name : ";
	cin >> name;
	s.setname(name);

	cout << "\n\t Please enter the password : ";
	cin >> pass;
	s.setpassword(pass);


	cout << "\n\n\t\t if he/she has finished courses enter 1 to write this courses : ";
	cin >> check;
	if (check)
	{
		int count;
		cout << "\t\t\n Enter the (Number) of courses : ";
		cin >> count;
		bool found = 0;
		for (int i = 0; i < count; i++)
		{
			cout << "\n\n\t Please enter the name of the finished course : ";
			cin >> finished;
			for (int j = 0; j < c.size(); j++)
			{
				if (c[j].getname() == finished)
				{
					s.setfinished_courses(c[i]);
					found = 1;
				}
			}
			if (!found)
			{
				cout << "\n\t\t This course is not found \n\n";
			}
			

		}

	}

	cout << "\n\t Please enter the academic year : ";
	cin >> academic_year;
	s.setacademic_year(academic_year);

	cout << "\n\t Your ID : " << s.getid() << endl;

	// I return (student_info s) to store in (vector <student_info>) in main
	return s;

}

Course Admin::addcourse()
{
	system("CLS");  // clear the console
	cout << "\n\n\t\t\t\t\t ADD COURSE \n\n\n\n";
	// I make variable (Course c) to store Course data and return it 
	Course c;

	// variables to store data and put it in c
	string name;
	string code;
	int num_of_student;
	string required;
	int hours;

	// to know how many requirements will be enter
	int count_req;

	// get course data
	cout << "\n\t Please enter the name : ";
	cin >> name;
	c.setname(name);

	cout << "\n\t Please enter the code : ";
	cin >> code;
	c.setcode(code);

	cout << "\n\t Please enter the number of students : ";
	cin >> num_of_student;
	c.setnum_of_student(num_of_student);

	cout << "\n\t Please enter the number of required : ";
	cin >> count_req;
	for (int i = 0; i < count_req; i++)
	{
		cout << "\n\t Please enter the required : ";
		cin >> required;
		c.setrequired(required);
	}

	cout << "\n\t Please enter the hours : ";
	cin >> hours;
	c.sethours(hours);


	// I return (Course c) to store in (vector <Course>) in main
	return c;
}

void Admin::view_students_in_a_specific_course(vector<student_info> s)
{
	system("CLS");  // clear the console
	cout << "\n\n\t\t\t\t\t VIEW LIST OF ALL STUDENTS IN A SPECIFIC COURSE. \n\n\n\n";
	// variable to store the name of course that we want to find him
	string search;

	cout << "\n\n\t\t Enter the course name : ";
	cin >> search;

	cout << "\n\n\t\t\t students \n";
	cout << "\t\t\t ******** \n\n";

	// it loop for each student
	for (int i = 0; i < s.size(); i++)
	{

		// variable to store the size of courses in progress of each student   
		// for remember the (courses_in_progress) his datatype is (vector<course>) so yes we can get his size
		int count_progress = s[i].courses_in_progress.size();

		// it loop for each course in progress for each student
		for (int j = 0; j < count_progress; j++)
		{

			// it check the name of courses in progress for each student == the name of course that we want to find him
			if (s[i].getcourses_in_progress(j).getname() == search)
			{
				// print student name
				cout << "\t\t\t " << s[i].getname() << "\n";
			}

		}

	}
}

bool Admin::admin_login(string name, string pass) {
	Admin admin;

	for (int i = 0; i < 2; i++)
	{
		if (name == admin.admin_name[i] && pass == admin.admin_pass[i])
		{
			cout << " \n\n\n\t\t\t                           ***You Logged in Successfuly***              \n \n \n ";
			return 1;
		}

	}
	cout << "\t\t\n Please Re-enter Your Data \n\n ";
	return 0;
}
void Admin::view_List_of_all_courses_in_aspecific_student(vector<student_info> s)
{
	system("CLS");  // clear the console
	cout << "\n\n\t\t\t\t\t VIEW LIST OF ALL COURSES IN A SPECIFIC STUDENT \n\n\n\n";

	string search;

	cout << "\n\n\t\t Enter the student name : ";
	cin >> search;

	cout << "\n\n\t\t\t courses\n\n";

	// it loop for each courses
	for (int i = 0; i < s.size(); i++)
	{
		//int count_progress = s[i].courses_in_progress.size();

		int count_progress2 = s[i].finished_courses.size();

		//it loops for each progress course in progress for a student

	   // it loops for each finished courses for a student
		for (int j = 0; j < count_progress2; j++)
		{

			// it check the name of courses that had finished for a student 
			if (s[i].getname() == search)
			{
				// print course name
				cout << "\t\t\t " << s[i].getfinished_courses(j).getname() << "\n\n";
			}

			// it loops for each finished courses for a student
			/*for (int j = 0; j < count_progress; j++)
			{

				// it check the name of courses that had finished for a student
				if (s[i].getname() == search)
				{
					// print course name
					cout << "\t\t\t " << s[i].getname() << "\n\n";
				}

			}*/
		}

	}
}
void Admin::edit_data_of_courses(vector<Course>& c)
{
	system("CLS");  // clear the console
	cout << "\n\n\t\t\t\t\t EDIT DATA OF COURSE \n\n\n\n";
	string index, require;
	int count_req;

	int newnum, newhours;
	cout << "\t\t Enter name of course : ";
	cin >> index;

	for (int i = 0; i < c.size(); i++) {
		if (c[i].getname() == index) {
			cout << "\n\t\t Enter the new number of student : ";
			cin >> newnum;

			cout << "\n\t Please enter the number of required : ";
			cin >> count_req;
			c[i].required.clear();
			for (int j = 0; j < count_req; j++)
			{
				cout << "\n\t Please enter the required : ";
				cin >> require;
				c[i].setrequired(require);
			}

			cout << "\n\t\t Enter the new hours :  ";
			cin >> newhours;

			c[i].setnum_of_student(newnum);
			c[i].sethours(newhours);


		}

	}
}