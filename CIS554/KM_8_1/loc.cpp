/*===============================================================*\
**
**  File Name     : loc.cpp
**  Creation Date : 03-06-2021
**  Last Modified : Sat 06 Mar 2021 02:16:00 PM PST
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
loc loc::operator+(loc op2) {
  loc temp;

  temp.longitude = op2.longitude + longitude;
  temp.latitude = op2.latitude + latitude;

  return temp;
}
