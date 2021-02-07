/*===============================================================*\
**
**  File Name     : Credit.h 
**  Creation Date : 02-4-2021
**  Last Modified : Fri 4 Feb 2021 12:19:52 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #2 - Excercise 4.14 p150
**  Description   : Header file/definitions for Credit.cpp
**  Organization  : Syracuse University
***==============================================================*/


#include <string.h>

#include <iostream>
using std::string;
class Credit {
 public:
  // create constructor and setters
  explicit Credit();
  void setAccount(int);
  void setBalance(float);
  void setCharges(float);
  void setCredit(float);
  void setLimit(float);

  // create getters
  int getAccount();
  float getBalance();
  float getCharges();
  float getCredit();
  float getLimit();

  // invoice total member function
  float getNewBalance();

  // all variables used by class
 private:
  int account;
  float balance;
  float charges;
  float credit;
  float limit;
  float newBalance;
};
