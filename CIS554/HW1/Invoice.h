/*===============================================================*\
**
**  File Name     : Invoice.cpp
**  Creation Date : 01-29-2021
**  Last Modified : Sun 07 Feb 2021 2:09:57 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #1 - Excercise 3.10 p100
**  Description   : Support file for Main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include <string.h>

#include <iostream>
using std::string;
class Invoice {
 public:
  // create constructor and setters
  explicit Invoice();
  void setNumber(string);
  void setDescription(string);
  void setQuantity(int);
  void setPrice(int);

  // create getters
  string getNumber();
  string getDescription();
  int getQuantity();
  int getPrice();

  // invoice total member function
  int getInvoiceAmount();

  // all variables used by class
 private:
  string number;
  string description;
  int quantity;
  int price;
  int total;
};
