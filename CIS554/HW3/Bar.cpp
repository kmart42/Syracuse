/*===============================================================*\
**
**  File Name     : Bar.cpp
**  Creation Date : 02-15-2021
**  Last Modified : Mon 15 Feb 2021 12:09:57 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #3 - Excercise 5.16 p206
**  Description   : Support file for Main.cpp
**  Organization  : Syracuse University
***==============================================================*/

#include<array>
#include "Bar.h"
using std::array;

// initialize constructor
Bar::Bar() {}

// setter to modify each input at specified array position
void Bar::setNumber(int position, int value) { 
	pos = position; 
	inputs[position] = value; 
}

// getter to return the value at the given position in array
int Bar::getNumber(int position) { return inputs[position]; }

// function to check if user input between 1 and 30
bool Bar::validNumber(int input) {
	if (input > 30 || input < 1) {
		return false;
	}
	else {
		return true;
	}
}