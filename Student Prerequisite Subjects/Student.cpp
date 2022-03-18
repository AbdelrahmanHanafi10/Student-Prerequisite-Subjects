#include "student.h"
#include "student_list.h"
#include"person.h"
#include<iostream>
#include <string>
#include<vector>
using namespace std;


student::student()
{

}


bool student::open(string nam, string pass, vector<student_info> s)
{

	// it loops for each student
	for (int i = 0; i < s.size(); i++)
	{
		if (pass == s[i].getpassword() && nam == s[i].getname())
		{
			cout << "  \n\n\n\t\t\t                          ***You Logged in Successfuly***              \n \n \n ";
			return 1;
		}

	}
	cout << "\t\t\n Please Re-enter Your Data \n\n ";
	return 0;
}

void student::view_all_courses(int num, vector<student_info> s)
{
	// variable to store the size of finished courses from a specific student
	int count_finish = s[num].finished_courses.size();

	// variable to store the size of courses in progress from a specific student
	int count_progress = s[num].courses_in_progress.size();

	cout << "\n\n\t\t\t ***********************\n\n";
	// it loops for each finished course from a specific student
	for (int i = 0; i < count_finish; i++)
	{
		Course c = s[num].getfinished_courses(i);
		cout << " \t Finished course : " << c.getname() << endl;
	}

	cout << "\n\n\t\t\t ***********************\n\n";
	cout << "\t\t\t ***********************\n\n";
	// it loops for each courses in progress from a specific student
	for (int i = 0; i < count_progress; i++)
	{
		Course c = s[num].getcourses_in_progress(i);
		cout << " \t Course in progress : " << c.getname() << endl;
	}

	cout << "\n\n\t\t\t ***********************\n\n";
}

void student::edit_data(vector<student_info>& s, string pass, int index)
{
	s[index].setpassword(pass);
}

void student::view_list_of_all_available_courses(vector<Course>c)
{
	cout << "\n\n\n\t\t\t\t\t  VIEW ALL AVAILABLE COURSES \n\n\n\n";

	for (int i = 0; i < c.size(); i++)
	{
		cout << "\n\t\t course " << i + 1 << " : " << c[i].getname() << endl;
	}
}

void student::view_details_of_a_specific_course(vector<Course>& c)
{
	system("CLS");  // clear the console
	cout << "\n\n\t\t\t\t\t  VIEW DETAILS OF A SPECIFIC COURSE \n\n\n\n";
	string name;

	cout << "\t\t Enter name of course : ";
	cin >> name;

	for (int i = 0; i < c.size(); i++) {
		if (c[i].getname() == name) {

			cout << "\n\t\t the number of student  : ";
			cout << c[i].getnum_of_student();

			cout << "\n\t\t the code is : ";
			cout << c[i].getcode();

			for (int j = 0; j < c[i].required.size(); j++) {
				cout << "\n\t\t the required is : ";
				cout << c[i].getrequired(j);
			}
			cout << "\n\t\t the hours are : ";
			cout << c[i].gethours();
		}
	}
}

void student::registerr_for_course(vector<Course>& c, vector<student_info>& s, int idr)
{
	cout << "\n\n\n\t\t\t\t\t  REGISTER FOR COURSE \n\n\n\n";

	bool check = 0;
	int index=0;

	cout << "\n\n\t\t Enter the course :" << endl;
	string courr;
	cin >> courr;

	for (int j = 0; j < c.size(); j++)
	{
		if (courr == c[j].getname()) {
			if (c[j].required.size() == NULL)
			{
				check = 1;
				index = j;
			}
			else {
				int coun = s[idr].finished_courses.size();
				for (int k = 0; k < coun; k++) {
					for (int m = 0; m < c[j].required.size(); m++) {
						if (s[idr].getfinished_courses(k).getname() == c[j].getrequired(m)) {

							check = 1;
							index = j;
						}

					}
				}
			}

		}

	}


	if (check == 1) {
		cout << "\n\n\t\tYour course in progress ." << endl;
		s[idr].setcourses_in_progress(c[index]);
	}
	else {
		cout << "\n\n\t\tyou should finish more courses" << endl;
	}




}