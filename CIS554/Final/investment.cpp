/*===============================================================*\
**
**  File Name     : investment.cpp
**  Creation Date : 03-15-2021
**  Last Modified : Tue 16 Mar 2021 10:00:13 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Abstract base class Investment and member functions
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "investment.h"

#include <chrono>
#include <ctime>
#include <iostream>
using std::cout;

// create constructor
Investment::Investment(const string &name, const double &price)
    : investmentName(name), investmentPrice(price) {
  // empty body
}

// get investment name
string Investment::getInvestmentName() const { return investmentName; }

// get investment price
double Investment::getInvestmentPrice() const { return investmentPrice; }

// set investment name
void Investment::setInvestmentName(const string &name) {
  investmentName = name;
}

// set investment price
// designed to accept a random price, generated later
void Investment::setInvestmentPrice(const double &price) {
  investmentPrice = price;
}

// default print function for Investment (base) class
void Investment::print() const {
  auto time = std::chrono::system_clock::now();
  std::time_t time_out = std::chrono::system_clock::to_time_t(time);
  cout << "\n"
       << getInvestmentName() << " trading at $" << getInvestmentPrice()
       << " at " << std::ctime(&time_out);
}
