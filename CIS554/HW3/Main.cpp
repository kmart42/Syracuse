/*===============================================================*\
**
**  File Name     : Main.cpp
**  Creation Date : 02-15-2021
**  Last Modified : Sat 15 Feb 2021 12:09:57 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #3 - Excercise 5.16 p206
**  Description   : Program to print number of asterisks based on user inputs
**  Organization  : Syracuse University
***==============================================================*/

#include <iostream>

#include "Bar.h"
using std::cin;
using std::cout;
using std::array;

int main() {
	// intialize the five variables for user input
	array<int, 5> stars;
	int index = 0;
	int out_index = 0;
	bool check = false;

	// welcome message
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "W | E | L | C | O | M | E\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Everyone loves a good bar!\n";
	cout << "But since we can't acutally go to one, let's print some instead!!\n";
	cout << "Enter five numbers, between 1 and 30, and press Enter after each\n";

	// intialize Bar class
	Bar bar;

	// loop for all five positions of input array
	for (int i = 0; i < 5; i++)
	{

		// prompt user for each number
		cout << "\nEnter number " << i+1 << ": ";
		cin >> stars[i];

		// check to see if number between 1-30
		check = bar.validNumber(stars[i]);

		// if input is not valid, enter while loop until valid input received
		while (not check) {
			cout << "Number must be between 1 and 30, try again: ";
			cin >> stars[i];
			check = bar.validNumber(stars[i]);
		}

		// after valid number received, set private array value accordingly
		bar.setNumber(i, stars[i]);
	}

	// successful input by user message
	cout << "\nThank you! Here is your bar chart:\n\n";

	// second loop to get each user value
	for (int j = 0; j < 5; j++) {
		out_index = bar.getNumber(j);
		
		// inner loop to pring asterisks
		for (int k = 1; k <= out_index; k++) {
			cout << "*";
		}
		cout << "\n";
	}
}
