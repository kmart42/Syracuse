/*===============================================================*\
**
**  File Name     : investment.h
**  Creation Date : 03-15-2021
**  Last Modified :
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Header file for base class, investment.cpp
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>
using std::string;

class Investment {
 public:
  // empty constructor
  explicit Investment();

  // string for name, double for price
  // only two characteristics all investments share
  Investment(const string &, const double &);

  // getter and setter for name
  string getInvestmentName() const;
  void setInvestmentName(const string &);

  // getter and setter for price
  double getInvestmentPrice() const;
  virtual void setInvestmentPrice(const double &);

  // virtual functions for calculating price and printing information
  // virtual double priceCalc() const = 0;
  virtual void print() const;

  // convert user choice (string) to vector index (int)
  int convertChoice(string, string);

  // validation that user has enough funds to buy investment
  bool validPurchase(double, double);

 private:
  // private data members
  string investmentName;
  double investmentPrice;
};

#endif
