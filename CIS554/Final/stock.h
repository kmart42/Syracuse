/*===============================================================*\
**
**  File Name     : stock.h
**  Creation Date : 03-16-2021
**  Last Modified :
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Header file for stock class, stock.cpp
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#ifndef STOCK_H
#define STOCK_H

#include "investment.h"

class Stock : public Investment {
 public:
  Stock(const string &, const double &, const string &, const double &);

  // new functions to get  and setstock exchange and volume for the day
  void setStockExchange(string);
  string getStockExchange() const;

  void setStockVolume(double);
  double getStockVolume() const;

  // override base class print function
  virtual void print() const;

 private:
  // private data members for stock class
  double stockVolume;
  string stockExchange;
};

#endif
