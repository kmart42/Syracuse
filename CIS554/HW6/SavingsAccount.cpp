/*===============================================================*\
**
**  File Name     : SavingsAccount.cpp
**  Creation Date : 03-06-2021
**  Last Modified : Sun 07 Mar 2021 05:34:28 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "SavingsAccount.h"

#include <iostream>

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
