/*===============================================================*\
**
**  File Name     : crypto.h
**  Creation Date : 03-16-2021
**  Last Modified :
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Header file for crypto class, crypto.cpp
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#ifndef CRYPTO_H
#define CRYPTO_H

#include "investment.h"

class Crypto : public Investment {
 public:
  Crypto(const string &, const double &);

  // override base class print function
  virtual void print() const;
};

#endif
