/*===============================================================*\
**
**  File Name     : main.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Tue 16 Mar 2021 09:55:29 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include <iomanip>
#include <iostream>
#include <vector>

#include "bond.h"
#include "crypto.h"
#include "investment.h"
#include "memestock.h"
#include "stock.h"

using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;
using std::vector;

int main() {
  cout << fixed << setprecision(2);

  vector<Investment *> investments(4);

  investments[0] = new Stock("TSLA", 400.00, "NYSE", 10000);
  investments[1] = new Bond("HNDA", 100.00, 3.2, 5);
  investments[2] = new Crypto("BTC", 50000);
  investments[3] = new MemeStock("GME", 230, "NASDAQ", 5000, 2);

  for (auto i : investments) {
    i->print();
  }
}

