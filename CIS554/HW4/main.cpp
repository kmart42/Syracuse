/*===============================================================*\
**
**  File Name     : main.cpp
**  Creation Date : 02-20-2021
**  Last Modified : Mon 22 Feb 2021 04:24:05 PM PST
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

  // intialize the cai class
  CAI cai;

  // main for loop, which iterates for 10 different questions before
  // printing user's overall score and terminating
  for (int pCount = 0; pCount < 10; pCount++) {
    // first print choices available
    cout << "\nChoose a problem:\n";
    cout << "Enter 1 for Addition\n";
    cout << "Enter 2 for Subtraction\n";
    cout << "Enter 3 for Multiplication\n";
    cout << "Enter 4 for Division\n";
    cout << "Enter 5 for a Random Mix!\n";

    // validate that user input is one of five available. If not,
    // enter loop until user makes a valid choice
    cin >> program;
    checkP = cai.validNumber(program);
    while (not checkP) {
      cout << "Please enter a valid choice from 1-5\n";
      cin >> program;
      checkP = cai.validNumber(program);
    }

    // after program validation, set private data member to user choice
    cai.setProgram(program);

    // repeat same process for difficulty
    cout << "\nNow select the difficulty:\n";
    cout << "Enter 1 for Single Digit\n";
    cout << "Enter 2 for Two Digits\n";
    cout << "Enter 3 for Three Digits\n";

    // validate difficulty selection, also using loop
    cin >> difficulty;
    checkD = cai.validNumber(difficulty);
    while (not checkD) {
      cout << "\nPlease enter a valid choice from 1-3\n";
      cin >> difficulty;
      checkD = cai.validNumber(difficulty);
    }

    // set private data member to user choice
    cai.setDifficulty(difficulty);

    // after both choices are made, generate a problem and prompt user for
    // answer
    cai.getProblem();

    // user input received here and private member updated
    cin >> usrInput;
    cai.setResult(usrInput);

    // user answer validated as either correct or incorrect, message printed,
    // total score updated and main loop starts over
    cai.checkAnswer();
    cout << "You have done " << pCount + 1 << " questions so far\n";
  }

  // after all 10 questions have been answerd, a final accuracy will be computed
  // and communicated to the user
  cai.checkAccuracy();
}
