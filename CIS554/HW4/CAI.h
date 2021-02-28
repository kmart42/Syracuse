#pragma once

/*===============================================================*\
**
**  File Name     : CAI.h
**  Creation Date : 02-21-2021
**  Last Modified : Sun 21 Feb 2021 12:19:52 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #4 - Excercise 6.57 - 6.61 p281
**  Description   : Header file/definitions for CAI.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include <string.h>

#include <array>
#include <iostream>
using std::string;
class CAI {
 public:
  // create constructor for class
  explicit CAI();

  // create setter for user's choice of program
  void setProgram(int);

  // set difficulty, used for random number generation as well
  void setDifficulty(int);

  // get response from list with index from random
  string getResponse(int, int);

  // generate random numbers for different ranges
  double randNum();

  // check function for data input
  bool validNumber(int);

  // generate main math problem
  void getProblem();

  // check user submitted answer
  bool checkAnswer();

  // check accuracy after 10 iterations
  void checkAccuracy();

  // set result based on user input
  void setResult(double);

 private:
  // all available responses, to be accessed by a random index number
  string posResponses[4] = {"Very good!", "Excellent!", "Nice work!",
                            "Keep up the good work!"};
  string negResponses[4] = {"No. Please try again.", "Wrong. Try once more.",
                            "Don't give up!", "No. Keep trying"};
  // private variables
  int program;
  double result;
  double response;
  int difficulty;
  double correct;
  double accuracy;
  double rand1;
  double rand2;
  int randIndex;
};
