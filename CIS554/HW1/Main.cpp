/*===============================================================*\
**
**  File Name     : Main.cpp
**  Creation Date : 01-29-2021
**  Last Modified : Sat 30 Jan 2021 12:12:47 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #1 - Exercise 3.10 p100
**  Description   : Demonstrate encapsulation with simple price and quantity
example using hardware store inventory
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>

#include "Invoice.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
  // intialize variables before user interaction
  string description;
  string number;
  int price;
  int quantity;
  int total;

  // prompt user for input details
  cout << "Enter item description, press enter ";
  cin >> description;
  cout << "Enter part number, press enter ";
  cin >> number;
  cout << "Enter item quantity, press enter ";
  cin >> quantity;
  cout << "Enter item price, press enter ";
  cin >> price;

  // initialize the invoice getInvoiceAmount
  // set variables of class based on user details
  Invoice invoice;
  invoice.setDescription(description);
  invoice.setNumber(number);
  invoice.setPrice(price);
  invoice.setQuantity(quantity);

  // calcualte total invoice, print a message to user
  total = invoice.getInvoiceAmount();
  cout << "Invoice total for " << invoice.getQuantity() << " "
       << invoice.getDescription() << "s (item number " << invoice.getNumber()
       << ") is: $" << total << endl;
}
