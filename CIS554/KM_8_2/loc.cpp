/*===============================================================*\
**
**  File Name     : loc.cpp
**  Creation Date : 03-06-2021
**  Last Modified : Sat 06 Mar 2021 02:55:04 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "loc.h"

loc::loc(int lon, int lat) : longitude(lon), latitude(lat) {}

void loc::show() {
  cout << longitude << " ";
  cout << latitude << "\n";
}

// Overload + for loc.
loc operator+(loc &op1, loc &op2) {
  loc temp;

  temp.longitude = op1.longitude + op2.longitude;
  temp.latitude = op1.latitude + op2.latitude;

  return temp;
}
