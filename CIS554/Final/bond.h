/*===============================================================*\
**
**  File Name     : bond.h
**  Creation Date : 03-16-2021
**  Last Modified : Fri 26 Mar 2021 11:45:33 AM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Header file for bond class, bond.cpp
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#ifndef BOND_H
#define BOND_H

#include "investment.h"

class Bond : public Investment {
 public:
  Bond(const string &, const double &, const double &, const int &);

  // new functions to get and set coupon and maturity
  void setBondRate(double);
  double getBondRate() const;

  void setBondMaturity(int);
  int getBondMaturity() const;

  // override base class print function
  virtual void print() const;

 private:
  // private data members for bond class
  double bondRate;
  int bondMaturity;
};

#endif
