#include<iostream>
using std::cout;
using std::cin;

long result(long);

int main()
{
	int num;
	cout << "enter number: ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "\n";
		cout << result(i);
	}
}

long result(long num)
{
	if (num <= 1)
		return 1;
	else
	{
		cout << num << "\n";
		return num + result(num - 1);
	}
}
