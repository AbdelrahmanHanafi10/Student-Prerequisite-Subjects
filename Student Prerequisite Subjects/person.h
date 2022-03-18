#pragma once
#include<string>
using namespace std;
class person
{
	string name;
	string password;

public:

	// set functions
	void setname(string name);
	void setpassword(string password);

	// get functions
	string getname();
	string getpassword();

	
};

