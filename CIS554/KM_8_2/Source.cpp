/*===============================================================*\
**
**  File Name     : Source.cpp
**  Creation Date : 03-06-2021
**  Last Modified : Sat 06 Mar 2021 02:16:26 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iostream>

#include "loc.h"
using std::cout;
using std::endl;

int main() {
  loc ob1(10, 20), ob2(5, 30), ob3;

  // demonstrate constructor
  cout << "Show proper construction of ob1 and ob2" << endl;
  cout << "Object ob1 = ";
  ob1.show();  // displays 10 20
  cout << "Object ob2 = ";
  ob2.show();  // displays 5 30
  cout << endl;

  // demonstrate operator+
  cout << "Show operator+" << endl;
  cout << "(ob1 + ob2).show= ";
  (ob1 + ob2).show();
  cout << endl;

  // default operator=
  cout << "Show default assignment operator" << endl;
  cout << "ob3 = ob1 + ob2 = ";
  ob3 = ob1 + ob2;
  ob3.show();
  cout << endl;

  // demonstrate that original loc objects have not been modified
  cout << "Show that original objects have not been modified" << endl;
  cout << "Object ob1= ";
  ob1.show();
  cout << "Object ob2= ";
  ob2.show();
  cout << endl;
}
