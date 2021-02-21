#include <iostream>
#include <iomanip>
#include<array>
using std::cout;
using std::setw;
using std::array;
using std::endl;

int main()
{
	const int n = 10;
	array< array<int, n>, n> arr;

	//for (size_t i = 0; i < n.size(); i++)
	for (auto& i : arr)
	{
		for (auto& k : i) {

			k = rand() % 100;
		}
	}
	//for (size_t j = 0; j < n.size(); j++)
	for (auto j : arr)
	{
		for (auto p : j) 
		{
			cout << setw(7) << p  << " ";
		}
		cout << "\n";
	}
}