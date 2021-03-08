/*===============================================================*\
**
**  File Name     : Main.cpp
**  Creation Date : 03-07-2021
**  Last Modified : Sun 07 Mar 2021 05:39:39 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #5 - Student Challenge
**  Description   : Protram to calcualte monthly interest rates and update
*balances for multiple investors/savers
**  Organization  : Syracuse University
***==============================================================*/

#include <iomanip>
#include <iostream>

#include "SavingsAccount.h"
using std::cout;
using std::fixed;

int main() {
  // initialize both savers
  SavingsAccount saver1;
  SavingsAccount saver2;

  // variables for balances
  float saver1Bal = 2000.00;
  float saver2Bal = 3000.00;

  // welcome message
  for (int i = 0; i < 7; i++) {
    cout << "*~*";
  }
  cout << "\nW E L C O M E\n";
  for (int j = 0; j < 7; j++) {
    cout << "*~*";
  }
  cout << "\nCongratulations! Making the decision to save for the future is a "
          "great decision!";
  cout << "\nFinanical education plays an important role in your success.";
  cout << "\nLet's take a look at how changing interest rates may affect your "
          "balance.";

  // stream manipulators to get desired formats
  cout << fixed << std::setprecision(2);

  // introduce both savers and show first case interest rate
  cout << "\n\nTo get started, let's first take a look at the monthly payments "
          "with a 3% annual interest rate";
  cout << "\nIndividual A has an inital balance of $2000.00, while Individual "
          "B has a balance of $3000.";

  // set interest rate to 3%
  saver1.modifyInterestRate(.03);
  saver2.modifyInterestRate(.03);

  // cacluate saver1
  cout << "\n Individual A will have to pay $"
       << saver1.calcualteMonthlyInterest() * saver1Bal << " per month";
  cout << "\n The new balance will be $"
       << saver1Bal - saver1.calcualteMonthlyInterest() * saver1Bal;

  // cacluate saver2
  cout << "\n Individual B will have to pay $"
       << saver2.calcualteMonthlyInterest() * saver2Bal << " per month";
  cout << "\n The new balance will be $"
       << saver2Bal - saver2.calcualteMonthlyInterest() * saver2Bal;

  // update interest rate
  cout << "\n\nNow let's see the results at a 4% interest rate";

  // set interest rate to 4%
  saver1.modifyInterestRate(.04);
  saver2.modifyInterestRate(.04);

  // cacluate updated saver1
  cout << "\n Individual B will have to pay $"
       << saver1.calcualteMonthlyInterest() * saver1Bal << " per month";
  cout << "\n The new balance will be $"
       << saver1Bal - saver1.calcualteMonthlyInterest() * saver1Bal;

  // cacluate updated saver2
  cout << "\n Individual B will have to pay $"
       << saver2.calcualteMonthlyInterest() * saver2Bal << " per month";
  cout << "\n The new balance will be $"
       << saver2Bal - saver2.calcualteMonthlyInterest() * saver2Bal;

  // ending message
  cout << "\n\nHopefully this helps illustrate the importance of a favorable "
          "interest rate!";
  cout << "\nGood luck out there!!\n\n";
}

