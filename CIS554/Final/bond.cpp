/*===============================================================*\
**
**  File Name     : bond.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Tue 16 Mar 2021 09:59:44 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "bond.h"

#include <iostream>

#include "investment.h"
using std::cout;

// create stock class constructor
// use base class constructor for fields from investment class
Bond::Bond(const string &name, const double &price, const double &rate,
           const int &maturity)
    : Investment(name, price) {
  // set bond specific fields
  setBondRate(rate);
  setBondMaturity(maturity);
}

// member functions to set rate and maturity
void Bond::setBondMaturity(int maturity) { bondMaturity = maturity; }
void Bond::setBondRate(double rate) { bondRate = rate; }

// member functions to return rate and maturity
double Bond::getBondRate() const { return bondRate; }
int Bond::getBondMaturity() const { return bondRate; }

// override base print function
void Bond::print() const {
  // reuse base class print
  Investment::print();
  // add bond specific items
  cout << "Has a coupon of " << getBondRate() << "% and matures in "
       << getBondMaturity() << " years\n";
}
