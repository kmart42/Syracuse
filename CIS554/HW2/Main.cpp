/*===============================================================*\
**
**  File Name     : Main.cpp
**  Creation Date : 02-4-2021
**  Last Modified : Fri 4 Feb 2021 12:09:58 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #2 - Excercise 4.14 p150
**  Description   : Program to determine whether a store customer has exceeded
* their credit limit on a charge account
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>

#include "Credit.h"
using std::cin;
using std::cout;

int main() {
    // intialize variables before user interaction
    int account = 0;
    float balance = 0;
    float charges = 0;
    float currCredit = 0;
    float limit = 0;
    float newBalance = 0;

    // welcome message
    cout << "*~*~*~ Welcome! *~*~*~";
    cout << "\nShall we extend some credit? Let's find out!\n";
    cout << "For each item, enter the relevant value and press Enter\n";

    while (account != -1) {
        // prompt user for input details
        cout << "\nEnter account number (or -1 to quit): ";
        cin >> account;
        if (account == -1) {
            break;
        }
        cout << "Enter beginning balance: ";
        cin >> balance;
        cout << "Enter total charges: ";
        cin >> charges;
        cout << "Enter total credits: ";
        cin >> currCredit;
        cout << "Enter credit limit: ";
        cin >> limit;

        // initialize the credit getNewBalance
        // set variables of class based on user details
        Credit credit;
        credit.setAccount(account);
        credit.setBalance(balance);
        credit.setCharges(charges);
        credit.setCredit(currCredit);
        credit.setLimit(limit);

        // calcualte total credit, print a message to user
        newBalance = credit.getNewBalance();
        cout << "New balance is ";
        cout << newBalance;
        if (newBalance > limit) {

            cout << "\nAccount: ";
            cout << credit.getAccount();
            cout << "\nCredit limit: ";
            cout << credit.getLimit();
            cout << "\nBalance: ";
            cout << credit.getBalance();
            cout << "\nCredit Limit Exceeded.\n";
        }
    }
}


