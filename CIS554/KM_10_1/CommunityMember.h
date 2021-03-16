///////////////////////////////////////////////////////////
// CommunityMember.h
// CIS554 Object Oriented Programming in C++
// Exercise 10_1 - Polymorphism
//                Class CommunityMember interface
///////////////////////////////////////////////////////////
#ifndef __COMMUNITY_MEMBER_H__
#define __COMMUNITY_MEMBER_H__

#include <string>
using std::string;

#include <ostream>
using std::ostream;

class CommunityMember {
 public:
  // default constructor
  // CommunityMember();

  // initialization constructor
  CommunityMember(string commName, string fName, string lName, int memID);

  // destructor
  //~CommunityMember();

  // virtual string GetCommunityName() { return communityName; }
  // virtual string GetFirstName() { return firstName; }
  // virtual string GetLastName() { return lastName; }
  // virtual int GetMemberID() { return memberID; }
  // virtual string GetCommunityMemberType() {

  virtual string GetCommunityName();
  virtual string GetFirstName();
  virtual string GetLastName();
  virtual int GetMemberID();
  virtual string GetCommunityMemberType();

 private:
  string communityName;
  string firstName;
  string lastName;
  int memberID;
};

#endif

