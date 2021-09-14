#include "Stock.h"

Stock::Stock(){}

Stock::Stock(std::string _n)
{
	mStockName = _n;
}

void Stock::printTradingDay(TradingDay _t)
{
	_t.printTradingDay();
}

void Stock::printTradingDays()
{
	std::cout << mStockName << std::endl;
	for (int i = 0; i < mTradingDays.size(); ++i)
	{
		mTradingDays.at(i).printTradingDay(); std::cout << std::endl;
	}
}

TradingDay Stock::getTradingDay(int _pos)
{
	return mTradingDays.at(_pos);
}

// return all the stock tradingdays data
std::string Stock::getTradingDays()
{
	std::string text;

	for (int i = 0; i < mTradingDays.size(); ++i)
	{
		text += this->mStockName + "\n" + mTradingDays.at(i).getData();
	}
	text += '\n\n';
	return text;
}

int Stock::getTotalTradingDays()
{
	return mTradingDays.size();
}

void Stock::setTradingDay(TradingDay _t)
{
	mTradingDays.push_back(_t);
}

void Stock::setStockName(std::string _stockName)
{
	mStockName = _stockName;
}

std::string Stock::getStockName()
{
	return mStockName;
}

void Stock::checkBullishEngulfing()
{
	for (int i = mTradingDays.size(); i > 0; --i)
	{
		int pos = i - 1;
		// variables to make the code more readable. Y is appended to the day before
		if (pos - 3 >= 0) // cant initialize the vars below if out of range in the vector
		{
			// 3 days before current day variables
			float close3 = mTradingDays.at(pos - 3).getClose(), open3 = mTradingDays.at(pos - 3).getOpen(), low3 = mTradingDays.at(pos - 3).getLow(),
				high3 = mTradingDays.at(pos - 3).getHigh(), vol3 = mTradingDays.at(pos - 3).getVol();

			// 2 days before current day variables
			float close2 = mTradingDays.at(pos - 2).getClose(), open2 = mTradingDays.at(pos - 2).getOpen(), low2 = mTradingDays.at(pos - 2).getLow(),
				high2 = mTradingDays.at(pos - 2).getHigh(), vol2 = mTradingDays.at(pos - 2).getVol();

			// 1 day before current day variables
			float close1 = mTradingDays.at(pos - 1).getClose(), open1 = mTradingDays.at(pos - 1).getOpen(), low1 = mTradingDays.at(pos - 1).getLow(),
				high1 = mTradingDays.at(pos - 1).getHigh(), vol1 = mTradingDays.at(pos - 1).getVol();

			float close = mTradingDays.at(pos).getClose(), open = mTradingDays.at(pos).getOpen(), low = mTradingDays.at(pos).getLow(),
				high = mTradingDays.at(pos).getHigh(), vol = mTradingDays.at(pos).getVol();


			if (pos - 3 >= 0 && close3 > open2 && open3 > close3)
			{
				if (pos - 3 >= 0 && close2 > open1 && close2 < open2)
				{
					// check if the preceeding day was a big red candle
					if (pos - 1 >= 0 && open1 > close1)
					{
						if (close1 / open1 <= 98.5) // the day closed 1.5 % lower or more
						{
							// check if this day opened lower than the day before closed
							if (pos - 1 >= 0 && open < close1)
							{
								// check if this day closed more than 1.5 % higher than this days open
								if (close / open >= 1.015)
								{
									//check if this days close was higher then the day befores open
									if (pos - 1 >= 0 && close > open1)
									{
										std::cout << "Bullish engulfing found in stock " << this->getStockName() << " Date: " << mTradingDays.at(pos).getDate() << "\n";
									}
								}
							}
						}
					}
				}
			}
		}
	}

}

void Stock::checkHighVol() // fixa parametrar till denna s� man kan v�lja hur l�ngt medelv�rdet och hur m�nga dagar tillbaka som ska vara med bl.a.
{
	// check for days with an vol much higher than average
	// get the average vol. Later I should only check for like the latest 15, 30 , 50 days something. This will be a huge number
	// will try the latest 20+- something trading days
	unsigned long long int  averageSum = 0, countedDays = 0;;
	int avgVol = 0;

	// Dont check stocks that have less than 20 tradingdays in total.
	if (mTradingDays.size() > 20)
	{
		for (int i = mTradingDays.size(); i > mTradingDays.size() - 20; --i)
		{
			int pos = i - 1;
			averageSum += mTradingDays.at(pos).getVol();
			countedDays++;

		}
		avgVol = averageSum / countedDays; // calc the average

		// check all the tradingdays if any is percentually much higher than the average
		for (int i = mTradingDays.size(); i > mTradingDays.size() - 20; --i)
		{
			int pos = i - 1;
			if (float(mTradingDays.at(pos).getVol() / avgVol) > 3.95)
			{
				std::cout << "High volume found in stock " << this->getStockName() << " " << mTradingDays.at(pos).getDate() << "\n";
			}
		}
	}
}

// make functions check for. doji candle. big green candle with high volume. evening and morning start.
// even make functions which checks for patterns like head and shoulder and triangle and such
// functions which finds trends?

// addso te program aoutomaticly opens the stock diagram at the webpage borsdata.se
// a program where you can click on the stock name to open the stock chart on a webpage
