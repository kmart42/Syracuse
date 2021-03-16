///////////////////////////////////////////////////////////
// Student.h
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                Class Student implementation
///////////////////////////////////////////////////////////

#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

// default constructor 
// initialize our data to something meaningful
Student::Student()
	: studentDepartment("Non-matriculated"), GPA(0.0)
{
	// no body needed. everthing was done in the initialization list
}

// initialization constructor
// initialize our base class with pertinent information
// then initialize this derived class data with the remaining pertinent data
Student::Student(string cName, string fName, string lName, int memID, string dept, double grades)
	: CommunityMember(cName, fName, lName, memID), studentDepartment (dept), GPA(grades)
{
	// no body needed. everthing was done in the initialization list
}

Student::~Student()
{
	// nothing to do at this time.
}
