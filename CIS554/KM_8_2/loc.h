///////////////////////////////////////////////////////////
// loc.h
// CIS554 Object Oriented Programming in C++
// Exercise 8_1 - Operator Overloading - member functions
//                Class loc interface
///////////////////////////////////////////////////////////
#ifndef __LOC_H__
#define __LOC_H__

#include <iostream>
using std::cout;

class loc {
  int longitude, latitude;

  friend loc operator+(loc&, loc&);

 public:
  loc(int lon = 0, int lat = 0);
  void show();
};

#endif __LOC_H__
