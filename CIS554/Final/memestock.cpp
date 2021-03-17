/*===============================================================*\
**
**  File Name     : memestock.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Tue 16 Mar 2021 10:01:28 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "memestock.h"

#include <iostream>

#include "investment.h"
using std::cout;

// constructor for memestock
MemeStock::MemeStock(const string &name, const double &price,
                     const string &exchange, const double &volume, int mult)
    : Stock(name, price, exchange, volume)

// set a multiplier to add volatility to price
{
  setMultiplier(mult);
}

void MemeStock::setMultiplier(int mult) { multipler = mult; }

// get multiplier back for computation
int MemeStock::getMultiplier() const { return multipler; }

// modifiy base print function
void MemeStock::print() const {
  cout << "\nReady to crank it up to 11?? Let's go!";
  // call stock print (not base, want to see exchange)
  Stock::print();
}
