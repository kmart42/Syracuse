/*===============================================================*\
**
**  File Name     : stock.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Wed 17 Mar 2021 06:39:22 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include "stock.h"

#include <iostream>

#include "investment.h"
using std::cout;

// create stock class constructor
// use base class constructor for fields from investment class
Stock::Stock(const string &name, const double &price, const string &exchange,
             const double &volume)
    : Investment(name, price) {
  // set stock specific fields
  setStockExchange(exchange);
  setStockVolume(volume);
}

// member function to set exchange
// uses a random function, just for fun/cosmetics
void Stock::setStockExchange(string exchange) { stockExchange = exchange; }

// return stock exchange
string Stock::getStockExchange() const { return stockExchange; }

// set daily volume
// also uses a random function
void Stock::setStockVolume(double volume) { stockVolume = volume; }

// return volume
double Stock::getStockVolume() const { return stockVolume; }

// override base print function
void Stock::print() const {
  // reuse base class print
  Investment::print();
  // add stock specific items
  cout << "Has traded " << getStockVolume() << " shares on the "
       << getStockExchange() << "\n";
}
