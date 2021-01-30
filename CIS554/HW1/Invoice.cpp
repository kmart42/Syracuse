/*===============================================================*\
**
**  File Name     : Invoice.cpp
**  Creation Date : 01-29-2021
**  Last Modified : Sat 30 Jan 2021 12:09:57 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #1 - Excercise 3.10 p100
**  Description   : Support file for Main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include "Invoice.h"

// create constructor and setters for private variables
Invoice::Invoice() {}
void Invoice::setNumber(string partNumber) { number = partNumber; }
void Invoice::setDescription(string partDescription) {
  description = partDescription;
}
void Invoice::setQuantity(int itemQuantity) { quantity = itemQuantity; }
void Invoice::setPrice(int itemPrice) { price = itemPrice; }

// getters for private variables
string Invoice::getNumber() { return number; }
string Invoice::getDescription() { return description; }
int Invoice::getQuantity() { return quantity; }
int Invoice::getPrice() { return price; }

// member function to calculate total invoice amount
// also checks to see if quantity or price is below 0, sets floor at 0
int Invoice::getInvoiceAmount() {
  if (quantity < 0) {
    quantity = 0;
  }
  if (price < 0) {
    price = 0;
  }
  total = price * quantity;
  return total;
}
