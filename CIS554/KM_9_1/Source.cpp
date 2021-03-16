///////////////////////////////////////////////////////////
// Source.cpp
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                program test
///////////////////////////////////////////////////////////

#include <iostream>

#include "CommunityMember.h"
#include "Employee.h"
#include "Student.h"
using std::cout;
using std::endl;

// Demonstrate CommunityMember class
void DemonstrateCommunityMember(CommunityMember &);

// Demonstrate Employee class
void DemonstrateEmployee(Employee &);

// Demonstrate Student class
void DemonstrateStudent(Student &);

int main() {
  // demonstrate CommunityMember default constructor
  cout << "***** Demonstrating the default constructor, and member methods, "
          "for class CommunityMember"
       << endl;
  CommunityMember commMember;
  DemonstrateCommunityMember(commMember);
  cout << endl;

  // demonstrate CommunityMember initialization constructor
  cout << "***** Demonstrating the initialization constructor, and member "
          "methods, for class CommunityMember"
       << endl;
  CommunityMember commMemberHarry("Syracuse University", "Harry", "Potter",
                                  1234);
  DemonstrateCommunityMember(commMemberHarry);
  cout << endl;

  // demonstrate Employee and Student default constructor
  cout << "***** Demonstrating the default constructor, and member methods, "
          "for class Employee and Student"
       << endl;
  Employee commMemberEmp;
  DemonstrateEmployee(commMemberEmp);
  Student commMemberStu;
  DemonstrateStudent(commMemberStu);
  cout << endl;

  // demonstrate Employee and Student initialization constructor
  cout << "***** Demonstrating the initialization constructor, and member "
          "methods, for class Employee and Student"
       << endl;
  Employee commMemberEmpHarry("Syracuse University", "Harry", "Potter", 1234,
                              "Janitor", 25000);
  DemonstrateEmployee(commMemberEmpHarry);
  Student commMemberStuHarry("Syracuse University", "Harry", "Potter", 1234,
                             "Electrical Engineering", 3.8);
  DemonstrateStudent(commMemberStuHarry);
  cout << endl;
}

void DemonstrateCommunityMember(CommunityMember &c) {
  cout << c.GetFirstName() << " " << c.GetLastName() << " is a member of the "
       << c.GetCommunityName() << " community, with member ID "
       << c.GetMemberID() << endl;
}

void DemonstrateEmployee(Employee &c) {
  cout << c.GetFirstName() << " " << c.GetLastName() << " is a member of the "
       << c.GetCommunityName() << " community, "
       << " with member ID " << c.GetMemberID() << endl
       << "He/She is an employee with Job Title: " << c.GetJobTitle()
       << ", making " << c.GetYearlySalary() << " per year." << endl;
}

void DemonstrateStudent(Student &b) {
  cout << b.GetFirstName() << " " << b.GetLastName() << " is a member of the "
       << b.GetCommunityName() << " community, "
       << " with member ID " << b.GetMemberID() << endl
       << "He/She is a student in the department: " << b.GetStudentDepartment()
       << ", with a GPA of " << b.GetGPA() << endl;
}
