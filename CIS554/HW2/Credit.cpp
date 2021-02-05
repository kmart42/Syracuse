/*===============================================================*\
**
**  File Name     : Credit.cpp
**  Creation Date : 02-4-2021
**  Last Modified : Fri 4 Feb 2021 12:09:57 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #2 - Excercise 4.14 p150
**  Description   : Support file for Main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include "Credit.h"

// create constructor and setters for private variables
Credit::Credit() {}
void Credit::setAccount(int acctNumber) { account = acctNumber; }
void Credit::setBalance(float currBalance) {
  balance = currBalance;
}
void Credit::setCharges(float newCharges) { charges = newCharges; }
void Credit::setCredit(float newCredit) { credit = newCredit; }
void Credit::setLimit(float newLimit) { limit = newLimit; }

// getters for private variables
int Credit::getAccount() { return account; }
float Credit::getBalance() { return balance; }
float Credit::getCharges() { return charges; }
float Credit::getCredit() { return credit; }
float Credit::getLimit() { return limit; }

// member function to calculate new account balance
float Credit::getNewBalance() {
  
  newBalance = balance + charges - credit;
  return newBalance;
}
