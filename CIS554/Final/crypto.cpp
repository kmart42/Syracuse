/*===============================================================*\
**
**  File Name     : crypto.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Fri 26 Mar 2021 11:47:21 AM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Crypto member class, inherits from Investment base
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "crypto.h"

#include <iostream>

#include "investment.h"

// create crypto class constructor
// use base class constructor for fields from investment class
Crypto::Crypto(const string &name, const double &price)
    : Investment(name, price) {
  // no new member functions
}

// override base print function
void Crypto::print() const {
  // reuse base class print
  Investment::print();
}
