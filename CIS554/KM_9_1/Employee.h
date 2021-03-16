///////////////////////////////////////////////////////////
// Employee.h
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                Class Employee interface
///////////////////////////////////////////////////////////
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "CommunityMember.h"
class Employee :
	public CommunityMember
{
public:

	// default constructor
	Employee();

	// initialization contstructor
	Employee(string cNname, string fName, string lName, int memID, string jobTitle, int yearlySalary);

	// destructor
	~Employee();

	string GetJobTitle() { return jobTitle; }
	int GetYearlySalary() { return yearlySalary; }

private:
	string jobTitle;
	int yearlySalary;
};

#endif

