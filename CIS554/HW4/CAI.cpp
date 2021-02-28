/*===============================================================*\
**
**  File Name     : CAI.cpp
**  Creation Date : 02-21-2021
**  Last Modified : Mon 22 Feb 2021 04:44:41 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #4 - Excercise 6.57 - 6.61 p281
**  Description   : Support file for main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include "CAI.h"

#include <array>
using std::cout;

// initialize constructor
CAI::CAI() {}

// set difficulty, based on user input
void CAI::setDifficulty(int diff) { difficulty = diff; };

// set program choice, based on user input
void CAI::setProgram(int prog) { program = prog; };

// get a random number with a designated range, for different difficulties
double CAI::randNum() {
  if (difficulty == 1) {
    return rand() % 4 + 1;
  }
  if (difficulty == 2) {
    return rand() % 9;
  } else
    return rand() % 99;
}

// generate the main math problem
void CAI::getProblem() {
  // first get the two numbers to be operated on
  rand1 = randNum();
  rand2 = randNum();

  // operation depends on user input
  cout << "How much is ";
  if (program == 1) {
    cout << rand1 << " plus " << rand2 << "?\n";
    result = rand1 + rand2;
  }
  if (program == 2) {
    cout << rand1 << " minus " << rand2 << "?\n";
    result = rand1 - rand2;
  }
  if (program == 3) {
    cout << rand1 << " times " << rand2 << "?\n";
    result = rand1 * rand2;
  }
  if (program == 4) {
    cout << rand1 << " divided by " << rand2 << "?\n";
    result = rand1 / rand2;
  }

  // if the user selects random, generate a random selection, call function
  if (program == 5) {
    // difficulty = 1;
    program = rand() % 4 + 1;
    getProblem();
  }
}

// set result based on user input
void CAI::setResult(double usrAnswer) { response = usrAnswer; }

// validate user input against math problem
bool CAI::checkAnswer() {
  if (response == result) {
    correct = correct + 1;
    cout << "\n" << CAI::posResponses[rand() % 3] << "\n";
    return true;
  } else {
    cout << "\n" << CAI::negResponses[rand() % 3] << "\n";
    return false;
  }
}

// after 10 loops, check overall accuracy
void CAI::checkAccuracy() {
  accuracy = correct / 10;

  // print a positive or negarive response, based on accuracy
  cout << "\nYou answered " << correct << " correctly out of 10\n";
  if (accuracy < .75)
    cout << "Please ask your teacher for extra help.\n";
  else
    cout << "Congratulations, you are ready to go to the next level!\n";
}

// function to check if user input between 1 and 5
bool CAI::validNumber(int input) {
  if (input > 5 || input < 1) {
    return false;
  } else {
    return true;
  }
}
