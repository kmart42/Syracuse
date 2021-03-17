/*===============================================================*\
**
**  File Name     : crypto.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Tue 16 Mar 2021 05:30:27 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
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
