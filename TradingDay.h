#pragma once
#include "Date.h"

class TradingDay 
{
	public:
		TradingDay();
	
		TradingDay(Date _d, float _c, float _o, float _l, float _h, unsigned long long int _v);
	
		void setData(Date _d, float _c, float _o, float _l, float _h, unsigned long long int _v);
	
		std::string getDate();
		float getClose();
		float getOpen();
		float getLow();
		float getHigh();
		unsigned long long int getVol();
		
		std::string getData();
	
		void printTradingDay();
	
	private:
		Date mDate;
		float mClose, mOpen, mLow, mHigh;
		unsigned long long int mVol;
		
};