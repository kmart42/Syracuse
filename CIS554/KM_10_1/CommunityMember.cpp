///////////////////////////////////////////////////////////
// CommunityMember.cpp
// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                Class CommunityMember implementation
///////////////////////////////////////////////////////////
#include "CommunityMember.h"

#include <iostream>
using std::cout;
using std::endl;

CommunityMember::CommunityMember(string cName, string firName, string lasName,
                                 int ID)
    : communityName(cName),
      firstName(firName),
      lastName(lasName),
      memberID(ID) {}
string CommunityMember::GetFirstName() { return "jane"; }
string CommunityMember::GetLastName() { return "doe"; }
string CommunityMember::GetCommunityName() { return "unknown"; }
int CommunityMember::GetMemberID() { return 0; }
string CommunityMember::GetCommunityMemberType() {
  return "My name is " + GetFirstName() + ". I am an Employee of the " +
         GetCommunityName() + " community!\n";
}
// default constructor
// initialize our data to something usefule
// CommunityMember::CommunityMember()
//    : communityName("Unknown"),
//     firstName("Jane"),
//    lastName("Doe"),
//   memberID(0) {
// no body needed. everthing was done in the initialization list
//}

// initialization constructor
// initialize our data to what the user requires
// CommunityMember::CommunityMember(string cName, string fName, string lName,
//                                int mID)
// : communityName(cName), firstName(fName), lastName(lName), memberID(mID) {
// no body needed. everthing was done in the initialization list
//}

// CommunityMember::~CommunityMember() {
// nothing to do at this time
//}
