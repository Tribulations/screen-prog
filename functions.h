#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "Stock.h"
using namespace std;

void readCSV(std::fstream& file, vector<Stock>& stocks, TradingDay& tradingDay, string fpath);

Stock readCSV(string filepath); // overload. new readSCV() test

void readFileNames(vector<string>& fileNames);

void readAmountOfFiles(string filepath, int numOfFiles);

void checkIfCorrectInput(string* input); // Sometimes some columns are missing data in a csv file so this function takes care of that

void formatVec(vector<string>& filenames); // only needed in windows!? Removes two last elements in vec

string formatName(string fn);

string formatSpecialC(string &text);