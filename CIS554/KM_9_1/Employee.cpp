///////////////////////////////////////////////////////////
// Employee.h
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                Class Employee implementation
///////////////////////////////////////////////////////////

#include "Employee.h"
#include <iostream>
using std::cout;
using std::endl;

// default constructor 
// initialize our data to something meaningful
Employee::Employee()
	: jobTitle("Unknown"), yearlySalary(0)
{
	// no body needed. everthing was done in the initialization list
}

// initialization constructor
// initialize our base class with pertinent information
// then initialize this derived class data with the remaining pertinent data
Employee::Employee(string cName, string fName, string lName, int memID, string jTitle, int yrSalary)
	: CommunityMember(cName, fName, lName, memID), jobTitle (jTitle), yearlySalary(yrSalary)
{
	// no body needed. everthing was done in the initialization list
}

Employee::~Employee()
{
	// nothing to do at this time.
}