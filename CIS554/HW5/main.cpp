/*===============================================================*\
**
**  File Name     : main.cpp
**  Creation Date : 03-01-2021
**  Last Modified : Tue 02 Mar 2021 02:17:36 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #5 - Student Challenge
**  Description   : Program to calcuate the reults of hypotehtical drag races
*based on power-to-weight ratios of user specific car details
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>
#include <vector>

#include "Cars.h"
using std::cin;
using std::cout;
using std::vector;

int main() {
  // intialize class
  Cars cars;
  // program variables;
  bool checkInput;
  double carPower;
  double carWeight;
  double ptow;
  double& result = ptow;
  double* powerPtr = &carPower;
  string carModel;
  int carTotal;
  vector<string> carModels;
  vector<double> carPowers;
  vector<double> carWeights;
  vector<double> carResults;

  // welcome message
  for (int i = 0; i < 7; i++) {
    cout << "*~*";
  }
  cout << "\nW E L C O M E\n";
  for (int j = 0; j < 7; j++) {
    cout << "*~*";
  }
  cout << "\nToo fast, too furious? Or not FAST enough? Let's find out!!";
  cout << "\nLet's run some hypothetical drag races and see who's number 1..";

  // promt user for inputs, first checking total cars
  cout << "\n\nFirst, how many cars would you like to check?\n";
  cin >> carTotal;

  // resize vector per user choice
  cout << "\nGreat! Now for the details\n";
  cout << "\nEnter your main car first, and the challengers after\n";

  // range based for loop to update each car
  for (int i = 0; i < carTotal; i++) {
    cout << "\nCar " << i + 1;
    cout << "\nEnter car model: ";
    cin >> carModel;
    cars.setModel(carModel);
    carModels.push_back(cars.getModel());

    cout << "\nEnter car horsepower: ";
    cin >> carPower;
    cars.setPower(powerPtr);
    carPowers.push_back(cars.getPower());

    cout << "\nEnter car weight: ";
    cin >> carWeight;
    carWeights.push_back(carWeight);
    cars.setWeight(carWeight);
    carResults.push_back(carPower / carWeight);

    // while loop to check for reasonableness
    // result variable is pass by value
    ptow = carPower / carWeight;
    checkInput = cars.validInput(result);
    while (not checkInput) {
      cout << "\n please update power and weight";
      cout << "\n New power: ";
      cin >> carPower;
      cout << "\nNew weight: ";
      cin >> carWeight;
      ptow = carPower / carWeight;
      checkInput = cars.validInput(result);
    }
  }

  // begin the results process
  cout << "\n";
  for (int i = 0; i < 7; i++) {
    cout << "|~|~";
  }

  // range based for loop
  cout << "\nThe contendors!\n";
  for (auto car : carModels) {
    cout << car << "  ";
  }
  cout << "\n";

  cout << "\nLet's check the results\n";
  // check all challengers against main car, print response
  // normal for loop
  for (int j = 1; j < carTotal; j++) {
    if (carResults[0] > carResults[j]) {
      cout << "The " << carModels[0] << " beats the " << carModels[j];
    } else {
      cout << "\nSurprising! The " << carModels[j] << " beat the "
           << carModels[0];
    }
    cars.printResponse(carResults[0], carResults[j]);
    cout << "\n";
  }

  // before program terminates, print safety warning
  cout << "\n\nThank you for playing, please remember to observe all posted \n"
          "speed limits and safe driving duidelines. The author of this \n"
          "program takes no responsiblity for any real world ramifcations. \n"
          "Results may vary based on conditions, tire choice, and driver "
          "skill.\n\n";
}
