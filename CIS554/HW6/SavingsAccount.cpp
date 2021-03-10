/*===============================================================*\
**
**  File Name     : SavingsAccount.cpp
**  Creation Date : 03-06-2021
**  Last Modified : Wed 10 Mar 2021 02:13:35 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "SavingsAccount.h"

#include <iostream>
using std::cout;

double SavingsAccount::annualInterestRate = .03;
// initialize constructor
SavingsAccount::SavingsAccount() {}

// calculate updated interest rate
double SavingsAccount::calcualteMonthlyInterest() {
  this->savingsBalance = this->annualInterestRate / 12;
  return savingsBalance;
};

// set annual interest rate
void SavingsAccount::modifyInterestRate(double newInterest) {
  SavingsAccount::annualInterestRate = newInterest;
};

// checks to make sure balances and interest rates are reasonable
// first, prompt the user for a positive starting balance
bool SavingsAccount::validBal(double balance) {
  if (balance < 0) {
    cout << "\nPlease enter a positive starting balance: ";
    return false;
  } else {
    return true;
  }
}

// make sure the interest is between 0% and 100%
bool SavingsAccount::validInt(double interest) {
  if (interest < 0 || interest > 1) {
    cout << "\nPlease enter an interest rate between 0%-100%: ";
    return false;
  } else {
    return true;
  }
}

// for updated interest rate, also check that it is not the same as first
bool SavingsAccount::validIntUpdate(double int1, double int2) {
  if (int1 < 0 || int1 > 1 || int1 == int2) {
    cout << "\nPlease enter an interest rate between 0%-100% and not equal to "
            "the original interest rate: ";
    return false;
  } else {
    return true;
  }
}
