#pragma once

class TimeDiff
{
public:
	TimeDiff(int, int, int);
	int checkSec(int &, int &, int &);
	int getHours();
	int getMinutes();
	int getSeconds();

private:
	bool validateTime(int, int, int);
	int hours;
	int minutes;
	int seconds;
};
