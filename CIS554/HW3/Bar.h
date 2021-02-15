#pragma once

/*===============================================================*\
**
**  File Name     : Bar.h
**  Creation Date : 02-15-2021
**  Last Modified : Mon 15 Feb 2021 12:19:52 PM PST
**  Compiler      : g++ -Wall -O2 -std=c++17
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Homework      : HW #3 - Excercise 5.16 p206
**  Description   : Header file/definitions for Bar.cpp
**  Organization  : Syracuse University
***==============================================================*/


#include<string.h>
#include<array>

#include <iostream>
#include <array>
using std::array;
class Bar {
public:
	// create constructor for class
	explicit Bar();

	// create setter for user input
	void setNumber(int, int);

	// create getter for program output
	int getNumber(int);

	// check function for data input
	bool validNumber(int);

	// array to store five numbers, position integer to keep track of index
private:
	array<int, 5> inputs;
	int pos;
};
