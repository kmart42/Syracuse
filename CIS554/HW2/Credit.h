#include <string.h>

#include <iostream>
using std::string;
class Credit {
 public:
  // create constructor and setters
  explicit Credit();
  void setAccount(int);
  void setBalance(float);
  void setCharges(float);
  void setCredit(float);
  void setLimit(float);

  // create getters
  int getAccount();
  float getBalance();
  float getCharges();
  float getCredit();
  float getLimit();

  // invoice total member function
  float getNewBalance();

  // all variables used by class
 private:
  int account;
  float balance;
  float charges;
  float credit;
  float limit;
  float newBalance;
};
