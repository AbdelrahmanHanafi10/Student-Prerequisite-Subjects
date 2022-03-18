

#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include"Student.h"
#include"student_list.h"
#include"Course.h"
#include"Admin.h"
using namespace std;

Course data_course(string name, string code, int num, int hour);
student_info data_student(int academic_year, string name, string password, vector<Course> c);

int main()
{
    vector<student_info> s;
    vector<Course> c;
    Admin admin;
    student stud;
    string name, password;
    int choose, continue_loop = 1;
    int chooseStud = 0;
    bool check;


    c.push_back(data_course("sp", "cs12", 20, 3));
    c.push_back(data_course("oop", "as12", 30, 3));
    s.push_back(data_student(1, "Ahmed", "123", c));
    s.push_back(data_student(1, "Ali", "125", c));





    do
    {
        system("CLS");  // clear the console
        cout << "\n\n\t\t\t\t\t WELCOME TO STUDENT PREREQUISITE SUBJECT \n\n\n\n";
        cout << "\n\n\n\t\t If you want to log in as Student enter 1, if you want to log in as admin enter 0 : ";
        cin >> chooseStud;
        cout << "\n\n\n\n\t Enter your name : ";
        cin >> name;
        cout << "\n\n\n\n\t Enter your password : ";
        cin >> password;
        if (chooseStud)
        {
            check = stud.open(name, password, s);
            if (check)
            {
                do
                {

                    system("CLS");  // clear the console
                    cout << "\n\n\t\t\t\t\t WELCOME TO STUDENT PREREQUISITE SUBJECT \n\n\n\n";
                    
                    cout << "\n\t\t\t\t 1- View List of all available courses." << endl;
                    cout << "\t\t\t\t 2- View details of specific course." << endl;
                    cout << "\t\t\t\t 3- Register for a course." << endl;
                    cout << "\t\t\t\t 4- View all courses." << endl;
                    cout << "\t\t\t\t 5- Edit your data. \n\n\n" << endl;
                    cout << "\n\n\n\t\tenter your choice :- (if you want to log out enter another number) : ";
                    cin >> choose;
                    system("CLS");  // clear the console
                    switch (choose) {

                    case 1:
                    {
                        stud.view_list_of_all_available_courses(c);
                        break;
                    }
                    case 2:
                    {
                        stud.view_details_of_a_specific_course(c);
                        break;
                    }

                    case 3:
                    {
                        int idr;
                        cout << "\n\t\t Enter your id :";
                        cin >> idr;

                        idr--;
                        stud.registerr_for_course(c, s, idr);
                        break;
                    }
                    case 4:
                    {
                        int index;
                        cout << "\n\t\t Enter your id :";
                        cin >> index;
                        index--;
                        stud.view_all_courses(index, s);
                        break;
                    }
                    case 5:
                    {

                        int index;
                        string newpass;
                        cout << "\n\n\t\t\t\t\t EDIT DATA OF STUDENT \n\n\n\n";
                        cout << "\n\t\t Enter your id :";
                        cin >> index;
                        cout << "\n\t\t Enter the new password : ";
                        cin >> newpass;
                        index--;
                        stud.edit_data(s, newpass, index);
                        break;
                    }
                    default:
                    {
                        cout << "You Logged Out \n";
                    }

                    }
                    //system("CLS");  // clear the console
                    cout << "\n\n\n\t\t\tIf you want to continue enter 1, if not enter another number: ";
                    cin >> continue_loop;
                    cout << "\n\n";
                } while (continue_loop == 1);
                system("CLS");  // clear the console

            }


        }
        else
        {
            check = admin.admin_login(name, password);

            if (check)
            {
                do {
                    system("CLS");  // clear the console
                    cout << "\n\n\t\t\t\t\t WELCOME TO STUDENT PREREQUISITE SUBJECT \n\n\n\n";
                    cout << "\n\t\t\t\t 1- Add new student." << endl;
                    cout << "\t\t\t\t 2- Add new course." << endl;
                    cout << "\t\t\t\t 3- View List of all students in a specific course." << endl;
                    cout << "\t\t\t\t 4- View List of all courses (Finished - Progressed) of a specific student." << endl;
                    cout << "\t\t\t\t 5- Edit all course data.\n\n" << endl;

                    cout << "\t\t Enter your choice : ";
                    cin >> choose;

                    switch (choose) {

                    case 1:
                    { s.push_back(admin.addstudent(c));
                    break;
                    }
                    case 2:
                    {
                        c.push_back(admin.addcourse());
                        break;
                    }

                    case 3:
                    {
                        admin.view_students_in_a_specific_course(s);
                        break;
                    }
                    case 4:
                    {
                        admin.view_List_of_all_courses_in_aspecific_student(s);
                        break;
                    }

                    case 5:
                    {
                        admin.edit_data_of_courses(c);
                        break;
                    }

                    }
                    //system("CLS");  // clear the console
                    cout << "\n\n\n\n\n\t\t\t If you want to continue enter 1, if not enter another number: ";
                    cin >> continue_loop;
                    cout << "\n\n";
                } while (continue_loop == 1);
                system("CLS");  // clear the console
            }

        }

    } while (true);


    return 0;
}


Course data_course(string name, string code, int num, int hour) {

    Course c;
    c.setname(name);
    c.setcode(code);
    c.setnum_of_student(num);
    c.sethours(hour);
    return c;
}

student_info data_student(int academic_year, string name, string password, vector<Course> c)
{
    student_info s;
    s.setname(name);
    s.setpassword(password);
    s.setacademic_year(academic_year);
    s.setfinished_courses(c[0]);
    return s;
}
