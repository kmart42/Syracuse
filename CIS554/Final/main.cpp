/*===============================================================*\
**
**  File Name     : main.cpp
**  Creation Date : 03-16-2021
**  Last Modified : Wed 17 Mar 2021 10:41:19 PM PDT
**  Compiler      : g++ -Wall -O2 -std=c++17
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
  int itr = 0;
  int stocks = 3;
  int bonds = 3;
  int coins = 3;
  int memes = 3;
  string ent = "";
  double user_balance = 0;
  string choice1 = "";
  int inv1 = 0;
  string choice2 = "";
  int inv2 = 0;
  string choice3 = "";
  int inv3 = 0;

  // format output stream
  cout << fixed << setprecision(2);

  // seed random, it will get used a lot
  srand(time(0));

  // initialize main vector that will display all available investments
  vector<Investment *> investments(13);

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

  // display welcome message
  cout
      << " _   _ ___________ _____ _   _ ______ _____  ___________ \n"
      << "| | | |  _  | ___ \\_   _| \\ | || ___ \\  _  ||  _  |  _  \\ \n"
      << "| |_| | | | | |_/ / | | |  \\| || |_/ / | | || | | | | | | \n"
      << "|  _  | | | | ___ \\ | | | . ` ||    /| | | || | | | | | | \n"
      << "| | | \\ \\_/ / |_/ /_| |_| |\\  || |\\  \\ \\_/ /\\ \\_/ / |/ / \n"
      << "\\_| |_/\\___/\\____/ \\___/\\_| \\_/\\_| \\_|\\___/  \\___/|___/ \n";

  cout << "\nWelcome! First, press enter to see how the markets are doing\n";
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

  // get user starting balance
  cout << "\n\nWhat a day! Enter the amount you would like to invest: $";
  cin >> user_balance;
  cout << "\nGreat! What would you like to buy?";
  cout << "\nChoose three investments. Totally up to you, but remeber, "
          "diversification is key!";

  // promt user for three choices, and convert strings to vector indices
  cout << "\nEnter first pick: ";
  cin >> choice1;
  cout << "Enter second pick: ";
  cin >> choice2;
  cout << "Enter third pick: ";
  cin >> choice3;

  // intialize empty investment
  Investment inv;

  inv1 = inv.convertChoice(choice1);
  inv2 = inv.convertChoice(choice2);
  inv3 = inv.convertChoice(choice3);

  cout << "\nchoice 1 " << inv1;
  cout << "\nchoice 2 " << inv2;
  cout << "\nchoice 3 " << inv3;
  cout << "\n";

  // for (auto i : investments) {
  // i->print();
  //}
}

