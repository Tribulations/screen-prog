#pragma once
#include "TradingDay.h"
#include <vector>
#include <string>

class Stock
{
	public:
		Stock();

		Stock(std::string _n);

		void printTradingDay(TradingDay _t);
		void printTradingDays();

		TradingDay getTradingDay(int _pos);

		std::string getTradingDays();

		int getTotalTradingDays();

		void setTradingDay(TradingDay _t);

		void setStockName(std::string _stockName);
		std::string getStockName();

		void checkBullishEngulfing();
		void checkHighVol();

	private:
		std::vector<TradingDay> mTradingDays;
		std::string mStockName;
};

// Lägga till vilken bransch aktien tillhör? Typ string bransch "Sällanköpsvaror";
