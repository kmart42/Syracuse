/*===============================================================*\
**
**  File Name     : Invoice.cpp
**  Creation Date : 01-29-2021
**  Last Modified : Fri 29 Jan 2021 02:01:52 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #1 - Excercise 3.10 p100
**  Description   : Support file for Main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include "Invoice.h"

Invoice::Invoice() {}
void Invoice::setNumber(string partNumber) { number = partNumber; }
void Invoice::setDescription(string partDescription) {
  description = partDescription;
}
void Invoice::setQuantity(int itemQuantity) { quantity = itemQuantity; }
void Invoice::setPrice(int itemPrice) { price = itemPrice; }

string Invoice::getNumber() { return number; }
string Invoice::getDescription() { return description; }
int Invoice::getQuantity() { return quantity; }
int Invoice::getPrice() { return price; }

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
