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
