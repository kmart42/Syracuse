/*===============================================================*\
**
**  File Name     : Main.cpp
**  Creation Date : 03-07-2021
**  Last Modified : Wed 10 Mar 2021 02:12:59 PM PST
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
using std::cin;
using std::cout;
using std::fixed;

int main() {
  // initialize both savers
  SavingsAccount saver1;
  SavingsAccount saver2;

  // variables for balances and interest rates
  float saver1Bal = 0.0;
  float saver2Bal = 0.0;
  float intRate = 0.0;
  float intRateUpdate = 0.0;
  bool checkBal1;
  bool checkBal2;
  bool checkInt;
  bool checkIntUpdate;

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
  cout << "\n\nTo get started, enter the first interest rate you would like to "
          "see: ";
  cin >> intRate;

  // validate a reasonable interest rate
  checkInt = saver1.validInt(intRate);
  while (not checkInt) {
    cin >> intRate;
    checkInt = saver1.validInt(intRate);
  }

  // enter starting balances for each saver
  cout << "\nNext, enter the starting balance for Individual A: ";
  cin >> saver1Bal;

  // validate saver1
  checkBal1 = saver1.validBal(saver1Bal);
  while (not checkBal1) {
    cin >> saver1Bal;
    checkBal1 = saver1.validBal(saver1Bal);
  }

  // perform same input and check for saver2
  cout << "\nFor comparison, enter a different starting balance for Individual "
          "B: ";
  cin >> saver2Bal;

  checkBal2 = saver2.validBal(saver2Bal);
  while (not checkBal2) {
    cin >> saver2Bal;
    checkBal2 = saver2.validBal(saver2Bal);
  }

  // set interest rate to first interest rate
  saver1.modifyInterestRate(intRate);
  saver2.modifyInterestRate(intRate);

  // cacluate saver1
  cout << "\n Individual A will earn $"
       << saver1.calcualteMonthlyInterest() * saver1Bal << " per month";
  cout << "\n The new balance will be $"
       << saver1Bal + saver1.calcualteMonthlyInterest() * saver1Bal;

  // cacluate saver2
  cout << "\n Individual B will earn $"
       << saver2.calcualteMonthlyInterest() * saver2Bal << " per month";
  cout << "\n The new balance will be $"
       << saver2Bal + saver2.calcualteMonthlyInterest() * saver2Bal;

  // update interest rate
  cout << "\n\nNow let's see the results at a new interest rate";
  cout << "\nEnter a new rate to see the updates: ";
  cin >> intRateUpdate;

  // validate new  interest rate
  checkIntUpdate = saver1.validIntUpdate(intRateUpdate, intRate);
  while (not checkIntUpdate) {
    cin >> intRateUpdate;
    checkIntUpdate = saver1.validIntUpdate(intRateUpdate, intRate);
  }

  // update to new chosen rate
  saver1.modifyInterestRate(intRateUpdate);
  saver2.modifyInterestRate(intRateUpdate);

  // cacluate updated saver1
  cout << "\n Individual B will earn $"
       << saver1.calcualteMonthlyInterest() * saver1Bal << " per month";
  cout << "\n The new balance will be $"
       << saver1Bal + saver1.calcualteMonthlyInterest() * saver1Bal;

  // cacluate updated saver2
  cout << "\n Individual B will earn $"
       << saver2.calcualteMonthlyInterest() * saver2Bal << " per month";
  cout << "\n The new balance will be $"
       << saver2Bal + saver2.calcualteMonthlyInterest() * saver2Bal;

  // ending message
  cout << "\n\nHopefully this helps illustrate the importance of a favorable "
          "interest rate!";
  cout << "\nGood luck out there!!\n\n";
}

