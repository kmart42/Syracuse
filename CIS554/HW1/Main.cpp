/*===============================================================*\
**
**  File Name     : Main.cpp
**  Creation Date : 01-29-2021
**  Last Modified : Sun 07 Feb 2021 06:35:54 AM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #1 - Exercise 3.10 p100
**  Description   : Demonstrate encapsulation with simple price and quantity
*example using hardware store inventory
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

  // welcome message
  for (int i = 0; i < 7; i++) {
    cout << "*~*";
  }
  cout << "\nW E L C O M E\n";
  for (int j = 0; j < 7; j++) {
    cout << "*~*";
  }
  cout << "\nTo calculate total invoice amount, enter each relevant value and "
          "press Enter\n";

  // prompt user for input details
  cout << "Enter item description: ";
  cin >> description;
  cout << "Enter part number: ";
  cin >> number;
  cout << "Enter item quantity: ";
  cin >> quantity;
  cout << "Enter item price: ";
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
