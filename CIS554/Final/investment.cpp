/*===============================================================*\
**
**  File Name     : investment.cpp
**  Creation Date : 03-15-2021
**  Last Modified : Wed 17 Mar 2021 10:37:28 PM PDT
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

// empty constructor for conversion function
Investment::Investment() {}

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
  cout << getInvestmentName() << " trading at $" << getInvestmentPrice()
       << " at " << std::ctime(&time_out);
}

// convert a user's input to vector index
int Investment::convertChoice(string input) {
  if (input == "TSLA" || input == "tsla") {
    return 0;

  } else if (input == "ABBV" || input == "abbv") {
    return 1;

  } else if (input == "NRG" || input == "nrg") {
    return 2;

  } else if (input == "HNDA" || input == "hnda") {
    return 3;

  } else if (input == "FNM" || input == "fnm") {
    return 4;

  } else if (input == "FHLD" || input == "fhld") {
    return 5;

  } else if (input == "BTC" || input == "btc") {
    return 6;

  } else if (input == "ETH" || input == "eth") {
    return 7;

  } else if (input == "DOGE" || input == "doge") {
    return 8;

  } else if (input == "GME" || input == "gme") {
    return 9;

  } else if (input == "AMC" || input == "amc") {
    return 10;

  } else if (input == "HTZGQ" || input == "htzgq") {
    return 11;

  } else
    return 12;
}
