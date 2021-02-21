#include <iostream>
#include <iomanip>
#include<array>
using std::cout;
using std::setw;
using std::array;
using std::endl;

int main()
{
	array<int, 10 > n;

	//for (size_t i = 0; i < n.size(); i++)
	for (int &i : n)
	{
		i = rand() % 100;
	}
	cout << "element" << setw(13) << "Value" << endl;
	//for (size_t j = 0; j < n.size(); j++)
	for (int j : n)
	{
		cout << setw(7) << j << setw(13) << j << endl;
	}
}