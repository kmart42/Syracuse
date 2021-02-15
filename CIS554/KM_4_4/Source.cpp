#include <iostream>
#include "TimeDiff.h"


using std::cin;
using std::cout;	
using std::endl;

int main()
{
	int hr;
	int min;
	int sec;
	int checkSec;

	cout << "W E L C O M E\n";

	cout << "\nenter hour ";
	cin >> hr;
	cout << "enter minute ";
	cin >> min;
	cout << "enter second ";
	cin >> sec;

	TimeDiff td{ hr, min, sec };

	cout << "\nhours: " << td.getHours();
	cout << "\nminutes: " << td.getMinutes();
	cout << "\nseconds: " << td.getSeconds();
	cout << "\n";

	checkSec = td.checkSec(hr, min, sec);
	if (checkSec == -1)
	{
		cout << "invalid time" << endl;
		return -1;
	}

	cout << "seconds since last noon: " << checkSec << endl;
}
