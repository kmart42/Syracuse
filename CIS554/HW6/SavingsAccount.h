/*===============================================================*\
**
**  File Name     : SavingsAccount.h
**  Creation Date : 03-06-2021
**  Last Modified : Sat 06 Mar 2021 02:55:04 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #6 - Savings Account Class, #9.20 p443
**  Description   : Header file/definitions for SavingsAccount.cpp
**  Organization  : Syracuse University
***==============================================================*/

#pragma once

class SavingsAccount {
 public:
  // create constructor class
  explicit SavingsAccount();
  // public function to calculate monthly interest rate
  double calcualteMonthlyInterest();

  // public function to modify annual interest rate
  static void modifyInterestRate(double);

  // annual interest rate to be charged to each customer
  static double annualInterestRate;

 private:
  // result of updating the savings balance information
  double savingsBalance;
};
