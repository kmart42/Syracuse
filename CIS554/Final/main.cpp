/*===============================================================*\
**
**  File Name     : main.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Fri 26 Mar 2021 02:07:50 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Description   : Investing game/app where user enters starting balance,
**                  selects 3 investments, and then watches the prices
**                  fluctuate randomly day over day. Ending balance and
**                  performance metrics are displayed.
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include <time.h>

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
  // varibles for main
  // dynamic iterators
  int itr = 0;
  int stocks = 3;
  int bonds = 3;
  int coins = 3;
  int memes = 3;
  int control = 0;
  // user information
  double user_balance = 0;
  double start_balance = 0;
  double cash = 0;
  string choice1 = "";
  double shares1 = 0;
  int inv1 = 0;
  string choice2 = "";
  double shares2 = 0;
  int inv2 = 0;
  string choice3 = "";
  double shares3 = 0;
  int inv3 = 0;
  bool balCheck = false;
  // edit here for new addition
  string profChoice = " ";

  // format output stream
  cout << fixed << setprecision(2);

  // seed random, it will get used a lot
  srand(time(0));

  // initialize main vector that will display all available investments
  vector<Investment *> investments(13);

  // create 12 investments, 3 of each type
  // randomly generate prices/volumes based on real world basis
  investments[0] =
      new Stock("TSLA", rand() % 20 + 400.01, "NYSE", rand() % 10000 + 51000);
  investments[1] =
      new Stock("ABBV", rand() % 10 + 100.02, "NYSE", rand() % 7000 + 23000);
  investments[2] =
      new Stock("NRG", rand() % 10 + 36.61, "NYSE", rand() % 2000 + 5200);
  investments[3] =
      new Bond("HNDA", rand() % 5 + 100.44, ((double)rand() / (RAND_MAX)) + 3.2,
               rand() % 2 + 5);
  investments[4] =
      new Bond("FNM", rand() % 2 + 101.23, ((double)rand() / (RAND_MAX)) + 1.2,
               rand() % 2 + 1);
  investments[5] =
      new Bond("FHLD", rand() % 2 + 103.05, ((double)rand() / (RAND_MAX)) + 1.1,
               rand() % 2 + 1);
  investments[6] = new Crypto("BTC", rand() % 200 + 50000);
  investments[7] = new Crypto("ETH", rand() % 50 + 1823.18);
  investments[8] = new Crypto("DOGE", ((double)rand() / (RAND_MAX)) + .06);
  investments[9] = new MemeStock("GME", rand() % 100 + 230, "NASDAQ",
                                 rand() % 1000 + 20000, 1);
  investments[10] =
      new MemeStock("AMC", rand() % 50 + 30, "NASDAQ", rand() % 500 + 5000, 1);
  investments[11] =
      new MemeStock("HTZGQ", rand() % 1 + 2.2, "NASDAQ", rand() % 200 + 800, 1);
  // add 13th investment here

  // display welcome message
  cout
      << " _   _ ___________ _____ _   _ ______ _____  ___________ \n"
      << "| | | |  _  | ___ \\_   _| \\ | || ___ \\  _  ||  _  |  _  \\ \n"
      << "| |_| | | | | |_/ / | | |  \\| || |_/ / | | || | | | | | | \n"
      << "|  _  | | | | ___ \\ | | | . ` ||    /| | | || | | | | | | \n"
      << "| | | \\ \\_/ / |_/ /_| |_| |\\  || |\\  \\ \\_/ /\\ \\_/ / |/ / \n"
      << "\\_| |_/\\___/\\____/ \\___/\\_| \\_/\\_| \\_|\\___/  \\___/|___/ \n";

  cout << "\nWelcome! Let's see how the markets are doing\n";
  cout << "\n\nCOMMON STOCK:\n";

  // print only the stocks first
  for (int i = itr; i < stocks; i++) {
    investments[i]->print();
  }

  // increment iterator for stocks
  itr = itr + stocks;

  // print the bonds
  cout << "\nBONDS:\n";
  for (int i = itr; i < itr + bonds; i++) {
    investments[i]->print();
  }

  // increment interator for bonds
  itr = itr + bonds;

  // print crypto
  cout << "\nCRYPTOCURRENCY:\n";
  for (int i = itr; i < itr + coins; i++) {
    investments[i]->print();
  }

  // increment interator for crypto
  itr = itr + coins;

  // print meme stocks
  cout << "\nMEME STOCKS:\n";
  for (int i = itr; i < itr + memes; i++) {
    investments[i]->print();
  }

  // print professor choice
  cout << "\nMYSTERY INVESTMENT:\n";
  if (profChoice == " ") {
    cout << "There's nothing here! Too bad..";
  } else {
    investments[12]->print();
  }

  // get user starting balance
  cout << "\n\nWhat a day! Enter the amount you would like to invest: $";
  cin >> user_balance;
  while (user_balance <= 0) {
    cout << "\nDon't be so negative! You'll have PLENTY Of time to lose all "
            "your money!";
    cout << "\nEnter a positivie starting balance: $";
    cin >> user_balance;
  }
  start_balance = user_balance;
  cout << "\nGreat! What would you like to buy?";
  cout << "\nChoose three investments. Totally up to you, but remeber, "
          "diversification is key!\n";

  // intialize empty investment
  Investment inv;

  // promt user for three choices, and convert strings to vector indices
  // enter while loops if funds are insufficient
  cout << "\nEnter first pick: ";
  cin >> choice1;
  inv1 = inv.convertChoice(profChoice, choice1);
  while (inv1 == -1) {
    cout << "\nInvalid entry, please enter a listed ticker: ";
    cin >> choice1;
    inv1 = inv.convertChoice(profChoice, choice1);
  }
  cout << "Number of shares/bonds/coins: ";
  cin >> shares1;
  double tmp1 = investments[inv1]->getInvestmentPrice() * shares1;
  balCheck = inv.validPurchase(tmp1, user_balance);
  while (not balCheck) {
    cout << "\nEnter first pick: ";
    cin >> choice1;
    inv1 = inv.convertChoice(profChoice, choice1);
    while (inv1 == -1) {
      cout << "\nInvalid entry, please enter a listed ticker: ";
      cin >> choice1;
      inv1 = inv.convertChoice(profChoice, choice1);
    }
    cout << "Number of shares/bonds/coins: ";
    cin >> shares1;
    tmp1 = investments[inv1]->getInvestmentPrice() * shares1;
    balCheck = inv.validPurchase(tmp1, user_balance);
  }

  // update user balance for purchase
  user_balance = user_balance - tmp1;
  cout << "\nCurrent balance is: " << user_balance;

  // second investment
  cout << "\nEnter second pick: ";
  cin >> choice2;
  inv2 = inv.convertChoice(profChoice, choice2);
  while (inv2 == -1) {
    cout << "\nInvalid entry, please enter a listed ticker: ";
    cin >> choice2;
    inv2 = inv.convertChoice(profChoice, choice2);
  }
  cout << "Number of shares/bonds/coins: ";
  cin >> shares2;
  double tmp2 = investments[inv2]->getInvestmentPrice() * shares2;
  balCheck = inv.validPurchase(tmp2, user_balance);
  while (not balCheck) {
    cout << "\nEnter second pick: ";
    cin >> choice2;
    inv2 = inv.convertChoice(profChoice, choice2);
    while (inv2 == -1) {
      cout << "\nInvalid entry, please enter a listed ticker: ";
      cin >> choice2;
      inv2 = inv.convertChoice(profChoice, choice2);
    }
    cout << "Number of shares/bonds/coins: ";
    cin >> shares2;
    tmp2 = investments[inv2]->getInvestmentPrice() * shares2;
    balCheck = inv.validPurchase(tmp2, user_balance);
  }

  // update user balance for purchase
  user_balance = user_balance - tmp2;
  cout << "\nCurrent balance is: " << user_balance;

  // third investment
  cout << "\nEnter third pick: ";
  cin >> choice3;
  inv3 = inv.convertChoice(profChoice, choice3);
  while (inv3 == -1) {
    cout << "\nInvalid entry, please enter a listed ticker: ";
    cin >> choice3;
    inv3 = inv.convertChoice(profChoice, choice3);
  }
  cout << "Number of shares/bonds/coins: ";
  cin >> shares3;
  double tmp3 = investments[inv3]->getInvestmentPrice() * shares3;
  balCheck = inv.validPurchase(tmp3, user_balance);
  while (not balCheck) {
    cout << "\nEnter third pick: ";
    cin >> choice3;
    inv3 = inv.convertChoice(profChoice, choice3);
    while (inv3 == -1) {
      cout << "\nInvalid entry, please enter a listed ticker: ";
      cin >> choice3;
      inv3 = inv.convertChoice(profChoice, choice3);
    }
    cout << "Number of shares/bonds/coins: ";
    cin >> shares3;
    tmp3 = investments[inv3]->getInvestmentPrice() * shares3;
    balCheck = inv.validPurchase(tmp3, user_balance);
  }

  // update user balance for purchase
  user_balance = user_balance - tmp3;
  // cash variable used to keep track of uninvested funds
  cash = user_balance;
  user_balance = start_balance - cash;
  // cout << "\nCurrent portfolio is: $" << user_balance;
  cout << "\nCash balance is : $" << cash;
  cout << "\n\nHere's your portoflio:";
  cout << "\n"
       << shares1 << " shares of " << investments[inv1]->getInvestmentName()
       << " at $" << investments[inv1]->getInvestmentPrice();
  cout << "\n"
       << shares2 << " shares of " << investments[inv2]->getInvestmentName()
       << " at $" << investments[inv2]->getInvestmentPrice();
  cout << "\n"
       << shares3 << " shares of " << investments[inv3]->getInvestmentName()
       << " at $" << investments[inv3]->getInvestmentPrice();
  cout << "\n\n";

  // main while loop to watch price movements
  while (control != -1) {
    cout << "\nTime for a new day, updated prices:\n";

    // update prices
    investments[inv1]->setInvestmentPrice(
        investments[inv1]->getInvestmentPrice() +
        (investments[inv1]->getInvestmentPrice() * (rand() % 41 + (-20)) /
         100.0));

    investments[inv2]->setInvestmentPrice(
        investments[inv2]->getInvestmentPrice() +
        (investments[inv2]->getInvestmentPrice() * (rand() % 41 + (-20)) /
         100.0));
    investments[inv3]->setInvestmentPrice(
        investments[inv3]->getInvestmentPrice() +
        (investments[inv3]->getInvestmentPrice() * (rand() % 41 + (-20)) /
         100.0));

    // display new prices
    investments[inv1]->print();
    investments[inv2]->print();
    investments[inv3]->print();

    // recalculate investor balance
    user_balance = (investments[inv1]->getInvestmentPrice() * shares1) +
                   (investments[inv2]->getInvestmentPrice() * shares2) +
                   (investments[inv3]->getInvestmentPrice() * shares3);

    cout << "\nYour total balance is now: $" << user_balance + cash;

    cout << "\n\nEnter 1 to keep going, enter -1 to tap out! ";
    cin >> control;
  }

  // exit while loop
  // final user balance
  user_balance = user_balance + cash;
  cout << "\nFinal portfolio value: $" << user_balance;
  cout << "\nStarting balance was: $" << start_balance;

  // calculate performance based on ending balance
  if (user_balance > start_balance) {
    cout << "\nYour account had a gain of: "
         << (user_balance - start_balance) / start_balance * 100;
  } else if (user_balance < 0) {
    cout << "\nOh no! You lost your shirt!! There was a margin call and, well, "
            "it's not looking good..";
    cout << "\nYou had a loss of : "
         << (user_balance - start_balance) / start_balance * 100;
  } else {
    cout << "\nYour account had a loss of: "
         << (user_balance - start_balance) / start_balance * 100;
  }
  cout << "%\n";
}

