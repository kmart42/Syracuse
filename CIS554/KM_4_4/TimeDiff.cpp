#include "TimeDiff.h"

TimeDiff::TimeDiff(int hr, int min, int sec) : hours{ hr }, minutes{ min }, seconds{ sec }
{}



int TimeDiff::checkSec(int & newHours, int & newMinutes, int & newSeconds)
{
int ssn = 0;
newHours = hours;
newMinutes = minutes;
newSeconds = seconds;

if (validateTime(hours, minutes, seconds))
{
	return -1;
}

if (newHours < 12)
{
	ssn += 43200;
}
else
	{
	newHours = newHours - 12;
	}

ssn += newHours * 60 * 60;
ssn += newMinutes * 60;
ssn += newSeconds;

return ssn;

}


bool TimeDiff::validateTime(int hr, int min, int sec)
{
	if (hr > 23 || min >= 60 || sec >= 60 || hr < 0 || min < 0 || sec < 0)
	{
		return true;
	}
	else {
		return false;
	}
}

int TimeDiff::getHours()
{
	return hours;
}
int TimeDiff::getSeconds()
{
	return seconds;
}
int TimeDiff::getMinutes()
{
	return minutes;
}