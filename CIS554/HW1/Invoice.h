#include <string.h>

#include <iostream>
using std::string;
class Invoice {
 public:
  // explicit Invoice(string, string, int, int);
  explicit Invoice();
  void setNumber(string);
  void setDescription(string);
  void setQuantity(int);
  void setPrice(int);

  string getNumber();
  string getDescription();
  int getQuantity();
  int getPrice();

  int getInvoiceAmount();

 private:
  string number;
  string description;
  int quantity;
  int price;
  int total;
};
