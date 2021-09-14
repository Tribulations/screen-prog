#include "Date.h"

Date::Date(){}

Date::Date(int _y, int _m, int _d)
{
	mYear = _y; mMonth = _m; mDay = _d;
	//mCurrentDate.push_back(mDay);
	//mCurrentDate.push_back(mMonth);
	//mCurrentDate.push_back(mYear);
}

void Date::printDate()
{
	std::cout << mYear << "-" << mMonth << "-" << mDay;
}

void Date::setYear(int _y)
{
	mYear = _y;
}

void Date::setMonth(int _m)
{
	mMonth = _m;
}

void Date::setDay(int _d)
{
	mDay = _d;
}

int Date::getYear()
{
	return mYear;
}
int Date::getMonth()
{
	return mMonth;
}
int Date::getDay()
{
	return mDay;
}
