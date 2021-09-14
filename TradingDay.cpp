#include "TradingDay.h"
#include <iomanip>
using namespace std;

TradingDay::TradingDay(){}

TradingDay::TradingDay(Date _d, float _c, float _o, float _l, float _h, unsigned long long int _v)
{
	mDate = _d; mClose = _c; mOpen = _o; mLow = _l; mHigh = _h; mVol = _v;
}

void TradingDay::setData(Date _d, float _c, float _o, float _l, float _h, unsigned long long int _v)
{
	mDate = _d; mClose = _c; mOpen = _o; mLow = _l; mHigh = _h; mVol = _v;
}

std::string TradingDay::getDate()
{
	return to_string(mDate.getYear()) + "-" + to_string(mDate.getMonth()) + "-" + to_string(mDate.getDay());
}

float TradingDay::getClose()
{
	return mClose;
}
float TradingDay::getOpen()
{
	return mOpen;
}
float TradingDay::getLow()
{
	return mLow;
}
float TradingDay::getHigh()
{
	return mHigh;
}
unsigned long long int TradingDay::getVol()
{
	return mVol;
}

std::string TradingDay::getData()
{
	string dataStr = to_string(mDate.getYear() ) + "-" + to_string(mDate.getMonth() ) + "-" + to_string(mDate.getDay() ) + '\t' + 
		to_string(mClose) + '\t' + to_string(mOpen) + '\t' + to_string(mLow) + '\t' + to_string(mHigh) + '\t' + to_string(mVol);

	return dataStr;
}

void TradingDay::printTradingDay()
{
	std::cout << mDate.getYear() << "-" << mDate.getMonth() << "-" << mDate.getDay() << '\t' << " "
		<< mClose << '\t' <<  mOpen << '\t' << mLow << " " << '\t' << mHigh << " " << '\t' << mVol;
}