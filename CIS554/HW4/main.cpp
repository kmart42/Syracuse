/*===============================================================*\
**
**  File Name     : main.cpp
**  Creation Date : 02-20-2021
**  Last Modified : Sun 21 Feb 2021 10:52:07 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #4 - Exercise 6.57 - 6.61 p281
**  Description   : Computer-assisted instruction to assist with student
**  fatigue, providing a dynamic environemnt to reinforce concepts
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>

#include "CAI.h"
using std::cin;
using std::cout;

int main() {
  // program variables
  bool checkP = false;
  bool checkD = false;
  double usrInput;
  int program = 0;
  int difficulty = 0;

  // welcome message
  for (int i = 0; i < 7; i++) {
    cout << "*~*";
  }
  cout << "\nW E L C O M E\n";
  for (int j = 0; j < 7; j++) {
    cout << "*~*";
  }
  cout << "\nThis is an interactive learning program, so you can make it "
          "whatever you want!\n";
  cout << "After 10 problems, we'll take a look at your progress!\n";
  cout << "To get started, first pick a math operation, then choose the "
          "difficulty\n";

  CAI cai;

  for (int pCount = 0; pCount < 5; pCount++) {
    cout << "\nChoose a problem:\n";
    cout << "Enter 1 for Addition\n";
    cout << "Enter 2 for Subtraction\n";
    cout << "Enter 3 for Multiplication\n";
    cout << "Enter 4 for Division\n";
    cout << "Enter 5 for a Random Mix!\n";

    cin >> program;
    checkP = cai.validNumber(program);
    while (not checkP) {
      cout << "Please enter a valid choice from 1-5\n";
      cin >> program;
      checkP = cai.validNumber(program);
    }

    cai.setProgram(program);

    cout << "\nNow select the difficulty:\n";
    cout << "Enter 1 for Single Digit\n";
    cout << "Enter 2 for Two Digits\n";
    cout << "Enter 3 for Three Digits\n";

    cin >> difficulty;
    checkD = cai.validNumber(difficulty);
    while (not checkD) {
      cout << "\nPlease enter a valid choice from 1-3\n";
      cin >> difficulty;
      checkD = cai.validNumber(difficulty);
    }

    cai.setDifficulty(difficulty);

    cai.getProblem();
    cin >> usrInput;
    cai.setResult(usrInput);
    cai.checkAnswer();
    cout << "You have done " << pCount + 1 << " questions so far\n";
  }

  cai.checkAccuracy();
}
