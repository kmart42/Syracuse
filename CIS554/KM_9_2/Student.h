///////////////////////////////////////////////////////////
// Student.h
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                Class Student interface
///////////////////////////////////////////////////////////
#ifndef __STDUENT_H__
#define __STUDENT_H__

#include "CommunityMember.h"
class Student : public CommunityMember {
 public:
  // default constructor
  Student();

  // initialization contstructor
  Student(string cNname, string fName, string lName, int memID,
           string dept, double grades);

  // destructor
  ~Student();

  string GetStudentDepartment() { return studentDepartment; }
  double GetGPA() { return GPA; }
  int GetMemberID() { return CommunityMember::GetMemberID() * 100; }


 private:
  string studentDepartment;
  double GPA;
};

#endif

