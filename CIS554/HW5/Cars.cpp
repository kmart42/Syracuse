/*===============================================================*\
**
**  File Name     : Cars.cpp
**  Creation Date : 03-01-2021
**  Last Modified : Wed 10 Mar 2021 01:52:08 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #5 - Student Challenge
**  Description   : Support file for main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include "Cars.h"
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using std::cout;

// initialize constructor
Cars::Cars() {}

// set car attributes
void Cars::setModel(string mod) { model = mod; };
void Cars::setPower(double* pow) { horsepower = *pow; };
void Cars::setWeight(double& lbs) { weight = lbs; };

// getters for car attributes
string Cars::getModel() { return model; };
double Cars::getPower() { return horsepower; };
double Cars::getWeight() { return weight; };

// calcuate power to weight
double Cars::powerToWeight() {
  powerWeight = horsepower / weight;
  return powerWeight;
}

// validate user inputs, and also reasonableness
// pass by value
bool Cars::validInput(double &pw) {
  if (pw > 50) {
    cout << "Are you sure about those numbers? A Hennessey Venom has "
            "power-to-weight of 55.87...\n";
    return false;
  } else {
    return true;
  }
}

// evaluate result and print resposne
void Cars::printResponse(double car1, double car2) {
srand(time(0));
  if (abs(car1 - car2) > .04) {
    cout << "\n" << Cars::blowoutResults[rand() % 3] << "\n";
  } else {
    cout << "\n" << Cars::closeResults[rand() % 3] << "\n";
  }
}
