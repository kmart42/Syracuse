/*===============================================================*\
**
**  File Name     : memestock.h
**  Creation Date : 03-16-2021
**  Last Modified : Tue 16 Mar 2021 03:55:51 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Description   : Header file for memestock class, memestock.cpp
**  Organization  : Syracuse University
***==============================================================*/

#ifndef MEMESTOCK_H
#define MEMESTOCK_H

// include stock, not base class
#include "stock.h"

// constructor, inherits from Stock (which inherits from Investment)
class MemeStock : public Stock {
 public:
  MemeStock(const string &, const double &, const string &, const double &,
            const int );

  // class specific multiplier for increased volatility
  void setMultiplier(int);
  int getMultiplier() const;

  // override base class price to add multiplier
  void setInvestmentPrice( const double &);
  double getInvestmentPrice() const;

  // oveerride base class print function
  virtual void print() const;

 private:
  // multipler private data member
  int multipler;
};

#endif
