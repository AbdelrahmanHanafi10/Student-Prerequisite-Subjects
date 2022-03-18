#pragma once
#include<string>
#include<vector>
using namespace std;
class Course 
{
	string name;
	string code;
	int num_of_student;
	int hours;

public:
	vector<string> required;

	Course();

	// set functions
	void setname(string name);
	void setcode(string code);
	void setnum_of_student(int num);
	void setrequired(string req);
	void sethours(int hours);

	// get functions
	string getname( );
	string getcode( );
	int getnum_of_student( );
	string getrequired(int index );
	int gethours( );

};

