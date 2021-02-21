#include <iostream>
#include <iomanip>
#include<array>
#include<vector>
using std::cout;
using std::setw;
using std::vector;
using std::endl;

int main()
{
	const int n = 10;
	vector< vector<int>> arr(n, vector<int> (n));

	//for (size_t i = 0; i < n.size(); i++)
	//for (auto& i : arr)
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t k = 0; k < 10;k++) {

			arr[i][k] = rand() % 100;
		}
	}
	//for (size_t j = 0; j < n.size(); j++)
	//for (auto j : arr)
	for (int m = 0; m < n; m++)
	{
		for (int p = 0; p < n; p++)
		{
			cout << setw(7) << arr[m][p] << " ";
		}
		cout << "\n";
	}
}