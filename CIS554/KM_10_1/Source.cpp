///////////////////////////////////////////////////////////
// Source.cpp
// CIS554 Object Oriented Programming in C++
// Exercise 10_1 - Polymorphism
//                program test
///////////////////////////////////////////////////////////

#include <iostream>

#include "CommunityMember.h"
#include "Employee.h"
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void PrintMemberType(CommunityMember *);

int main() {
  // create a vector of default CommunityMember objects
  vector<CommunityMember *> communityMemberVector(2);

  // initialize some CommunityMember objects
  CommunityMember taylorSwift("Syracuse University", "Taylor", "Swift", 1234);
  Employee carrieUnderwood("Syracuse University", "Carrie", "Underwood", 5678,
                           "Country Singer", 1000000);

  // re-assign default objects in our vector to our newly created members
  communityMemberVector[0] = &taylorSwift;      // CommunityMember type
  communityMemberVector[1] = &carrieUnderwood;  // Employee type

  // print out each member's type
  // for (auto item : communityMemberVector) {
  for (int i = 0; i < communityMemberVector.size(); i++)
    PrintMemberType( communityMemberVector[i]);
}

// method to print out CommunityMember types given a CommunityMember object
void PrintMemberType(CommunityMember *member) {
  cout << member->GetCommunityMemberType();
  cout << "\nmy name is " << member->GetFirstName() << " "
       << member->GetLastName() << " in dept " << member->GetCommunityName()
       << "\n";
}

