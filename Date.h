#pragma once
#include <iostream>
#include <string>
#include <vector>

class Date
{
	public:
		Date();

		Date(int _y, int _m, int _d);

		void printDate();

		void setYear(int _y);

		void setMonth(int _m);

		void setDay(int _d);

		int getYear();
		int getMonth();
		int getDay();

	private:
		int mYear, mMonth, mDay;
		//std::vector<int> mCurrentDate;
};
