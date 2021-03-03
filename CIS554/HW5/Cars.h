#pragma once

/*===============================================================*\
**
**  File Name     : Cars.h
**  Creation Date : 03-1-2021
**  Last Modified : Mon 1 Mar 2021 12:19:52 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #5 - Student Challenge
**  Description   : Header file/definitions for Cars.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include <string.h>

#include <array>
#include <iostream>
using std::array;
using std::string;

class Cars {
 public:
  // create class constructor
  explicit Cars();

  // create setters for attributes
  // pass by pointer
  void setPower(double*);
  // pass by value
  void setWeight(double&);
  // pass by reference
  void setModel(string);

  // create getters for vector
  string getModel();
  double getPower();
  double getWeight();

  // check user input to be valid
  bool validInput(double&);

  // calcuate power to weight
  double powerToWeight();

  // print response from race
  void printResponse(double, double);

 private:
  // fixed length arrays used to print message based on how close the race was
  array<string, 3> closeResults = {
      "Doesn't matter if you win by an inch or a mile, winning is winning!",
      "Wow that was close!",
      "Another few seconds and you never know what could have happened..."};
  array<string, 3> blowoutResults = {
      "You never had me, you never had your car!",
      "Come on, my grandma is a better driver", "Hmm, maybe try knitting?"};

  // variables
  double horsepower;
  double weight;
  string model;
  double powerWeight;
};
