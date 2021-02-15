#include<iostream>
#include"maximum.h"
using std::cout;
using std::cin;

int main()
{
	int int1, int2, int3, int4;

		cout << "Input four: ";
		cin >> int1 >> int2 >> int3 >> int4;

		cout << "Max value is: " << maximum(int1, int2, int3, int4);

		double double1, double2, double3, double4;

		cout << "\n\nInput four doubles: ";
		cin >> double1 >> double2 >> double3 >> double4;

		cout << "Max double is: " << maximum(double1, double2, double3, double4);

			
}