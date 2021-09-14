#include "functions.h"

// read and take the data from each column and put into their own variables. This is so we can make calculations with the data.
void readCSV(fstream& file, vector<Stock>& stocks, TradingDay& tradingDay, string fpath)
{
	int tradingDayscounter = 0;

	std::string tempSubStr, closeStr, openStr, lowStr, highStr, volStr, text;
	Stock stock;
	std::string stockName = formatName(fpath);
	stock.setStockName(stockName);

	file.open(fpath, std::ios::in);
	if (file.is_open())
	{
		while (getline(file, text)) // puts the whole line in to variable text
		{
			size_t pos = text.rfind(',');
			volStr = text.substr(pos + 1);
			checkIfCorrectInput(&volStr);

			tempSubStr = text.substr(0, pos); // new substring with all data with out the last data on the current row
			pos = tempSubStr.rfind(',');
			highStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&highStr);

			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind(',');
			lowStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&lowStr);

			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind(',');
			openStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&openStr);

			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind(',');
			closeStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&closeStr);

			Date date; // store the current date in date object

			//the current day
			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind('-');
			date.setDay(stoi(tempSubStr.substr(pos + 1)));
			//the current month
			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind('-');
			date.setMonth(stoi(tempSubStr.substr(pos + 1)));
			//the current year
			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind('-');
			date.setYear(stoi(tempSubStr.substr(pos + 1)));

			char *end; // i think this is the null char and this is needed in the strtoull() below. The func makes volStr a big integer I think :) dont remember when writing this comment.
			// set the current tradingDays variables
			tradingDay.setData(date, stof(closeStr), stof(openStr), stof(lowStr), stof(highStr), strtoull((volStr.c_str()), &end, 10));
			stock.setTradingDay(tradingDay);

			tradingDayscounter++;
		}
	}
	else
	{
		cout << "Unable to open the file: " << fpath << endl;
	}
	stocks.push_back(stock);
	file.close();
}


// new readCSV() this one should use read a csv file and then put the data in top a stock and then return the stock.
Stock readCSV(string filepath)
{
	int tradingDayscounter = 0;
	std::string tempSubStr, closeStr, openStr, lowStr, highStr, volStr, text;
	Stock stock;
	TradingDay tradingDay;
	fstream file;

	std::string stockName = formatName(filepath); // the filepath needs to be formatted so the stock name only holds the name of the stock
	stock.setStockName(stockName);

	file.open( formatSpecialC(filepath ), std::ios::in);
	if (file.is_open())
	{
		while (getline(file, text)) // puts the whole line in to variable text
		{
			size_t pos = text.rfind(',');
			volStr = text.substr(pos + 1);
			checkIfCorrectInput(&volStr);

			tempSubStr = text.substr(0, pos); // new substring with all data with out the last data on the current row
			pos = tempSubStr.rfind(',');
			highStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&highStr);

			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind(',');
			lowStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&lowStr);

			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind(',');
			openStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&openStr);

			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind(',');
			closeStr = tempSubStr.substr(pos + 1);
			checkIfCorrectInput(&closeStr);

			Date date; // store the current date in date object

			//the current day
			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind('-');
			date.setDay(stoi(tempSubStr.substr(pos + 1)));
			//the current month
			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind('-');
			date.setMonth(stoi(tempSubStr.substr(pos + 1)));
			//the current year
			tempSubStr = text.substr(0, pos);
			pos = tempSubStr.rfind('-');
			date.setYear(stoi(tempSubStr.substr(pos + 1)));

			char *end; // i think this is the null char and this is needed in the strtoull() below. The func makes volStr a big integer I think :) dont remember when writing this comment.
			// set the current tradingDays variables
			tradingDay.setData(date, stof(closeStr), stof(openStr), stof(lowStr), stof(highStr), strtoull((volStr.c_str()), &end, 10));
			stock.setTradingDay(tradingDay);

			tradingDayscounter++;
		}
	}
	else
		cout << "Unable to open the file: " << filepath << endl;

	file.close();
	return stock;
}


//WIn version
//dir/b/a-d C:\Users\Jocke\Desktop\Stock\ScrapeDatabase | find /v /c "::"
// this function should get all the names of the csv files and put them into a vector of strings. Takes a vector<string>& as argument
/*
void readFileNames(vector<string>& fileNames)
{
	string cmd = "dir C:\\Users\\Jocke\\Desktop\\Stock\\ScrapeDatabase";
	string filename = "C:\\Users\\Jocke\\Desktop\\Stock\\dir.txt", filepath, line; // line is a temp var to store the filepath of the csv file eg. AAK.csv or AAB.csv
	int lineCounter = 1;

	system((cmd + " > " + filename).c_str());

	ifstream myfile(filename);

	if ( myfile.is_open() )
	{
		while ( getline( myfile, line ) )
		{
			//if we are at line 8 which is the first line with a stock filepath
			if (lineCounter >= 8)
			{
				filepath = line.substr( 36 );
				fileNames.push_back(filepath);
				//cout << filepath << endl; // for debugging
			}
			lineCounter++;
		}
		myfile.close();
	}
	else
		cout << "Unable to open the file " << filename << endl;

	//readAmountOfFiles("C:\\Users\\Jocke\\Desktop\\Stock\\dir.txt", numOfFiles); // this function works and returns the num of files in the stocks folder
	formatVec(fileNames);// remove two last elements which isnt filenames
}
*/
//***	LINUX VERSION	*******
//__		_____		____//

void readFileNames(vector<string>& fileNames)
{
	string cmd = "ls";
	string filename = "/home/pi/sharedFolder/Scraping/dir.txt";
	//string path = "/home/jocke/projects/stockfileToRead";

	//vector<string> fileNames;
	string filepath;
	int numOfFiles = 0;
	//string numOfFile
	size_t pos = 36;
	size_t posFileAmount = 13;

	int counter = 0;
	int counter2 = 0;

	system(("ls -l /home/pi/sharedFolder/Scraping/database > " + filename).c_str());

	string line;
	ifstream myfile(filename);

	// save the amount of files in variable.
	// we have to do this first before the follow�ng stuff.
	int lineCounter = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (lineCounter >= 1) // skip the first line when using the ls -l command
			{
				filepath = line.substr(37);	// save only the last column from the line
				fileNames.push_back(filepath);
				//cout << filepath << endl;
			}
			lineCounter++;
		}
		myfile.close();
	}
	else
		cout << "Unable to open the file";

	//readAmountOfFiles("/home/pi/sharedFolder/Scraping/dir.txt", numOfFiles);

	// here im wrting all the filenames saved in the fileNames vector to a file.
	ofstream myfile2;
	myfile2.open(filename);

	if (myfile2.is_open()) {

		for (int i = 0; i < fileNames.size(); ++i)
		{
			myfile2 << fileNames.at(i) << "\n";
		}
		myfile2.close();
	}
	else
	{
		cout << "Unable to open the file";

	}
	//cout << "num of files = " << numOfFiles;
}



// Win version
/*
void readAmountOfFiles(string filepath, int numOfFiles)
{
	string path = "C:\\Users\\Jocke\\Desktop\\Stock\\ScrapeDatabase";
	string command = "dir/b/a-d C:\\Users\\Jocke\\Desktop\\Stock\\ScrapeDatabase | find /v /c \"\:\:\"";
	string line;
	ifstream myfile;
	myfile.open(filepath);

	system(command.c_str());
	// get the num of fies into a variable
	myfile.open("C:\\Users\\Jocke\\Desktop\\Stock\\filesTotal.txt");
	if (myfile.is_open()) {

		while (getline(myfile, line)) {
			//cout << line << endl;
			//if we are at line 8 which is the first line with a stock filepath

			// get the amount of files from the next to last line from the file and save it to variable.


			numOfFiles = stoi(line);
			cout << numOfFiles << endl;
		}
		myfile.close();
	}
	else
		cout << "Unable to open the file";
}
*/

//Linux version

void readAmountOfFiles(string filepath, int numOfFiles)
{

	string line;
	ifstream myfile;
	myfile.open(filepath);

	system("ls | wc -l > /home/pi/sharedFolder/Scraping/dir.txt");
	// get the num of fies into a variable
	myfile.open("/home/pi/sharedFolder/Scraping/dir.txt");
	if (myfile.is_open()) {

		while (getline(myfile, line)) {
			//cout << line << endl;
			//if we are at line 8 which is the first line with a stock filepath

			// get the amount of files from the next to last line from the file and save it to variable.


			numOfFiles = stoi(line);
			cout << numOfFiles << endl;
		}
		myfile.close();
	}
	else
		cout << "Unable to open the file";
}


// funktion som kontrollerar ifall någon kolumn för en tradingDag saknar data som t.ex. 2020-10-25,20,22,,, istället för 2020-10-25,20,22,19,25,150111
void checkIfCorrectInput(string* input)
{
	if (*input == "")
		*input = "0";

	if (*input == " ")
		*input = "0";
}

// function which removes the two last objects int the filename vector. Only needed in Windows!?
void formatVec(vector<string>& filenames)
{
	//remove last two objects
	filenames.pop_back();
	filenames.pop_back();
}

// WIN VERSION
//make function which parses the filename string and removes only the name of the share, eg. aak.csv --> aak or AAB.csv --> AAB. should return a string with only the name of the share
/*
string formatName(string fn)
{
	// get the size of the string and then strip of the last for chars which are the .csv letters
	fn = fn.substr(0, fn.size() - 4);
	//cout << "stripped str " << newStr << endl;

	size_t posEnd = fn.rfind('.'); // go up to the point of the dot(.) min the filename string
	//string newStr = fn.substr(posEnd + 1);
	size_t posBeg = fn.rfind('\\');// go to the point of the \ in the filename
	fn = fn.substr(posBeg + 1);

	return fn;
}
*/

// Linux Version ***|
//

string formatName(string fn)
{
	// get the size of the string and then strip of the last for chars which are the .csv letters
	fn = fn.substr(0, fn.size() - 4);
	//cout << "stripped str " << newStr << endl;

	size_t posEnd = fn.rfind('.'); // go up to the point of the dot(.) min the filename string
	//string newStr = fn.substr(posEnd + 1);
	size_t posBeg = fn.rfind('/');// go to the point of the \ in the filename
	fn = fn.substr(posBeg + 1);

	return fn;
}


// maybe use this or not ???
string formatSpecialC(string &text)
{
	char aDot = '\u00C5';	// Å eller det tecken denna dator tror är Å och Ä, Ö när det finns med i en filepath
	char aDots = '\u00C4'; // Ä
	char oDots = '\u00D6';	// Ö

	for (int i = 0; i < text.length(); ++i)
	{
		if (text[i] == '\x8F') //Å = \x8F detta visar ett Å på skärmen men tolkas inte som ett Å från en filepath
			text[i] = aDot;

		if (text[i] == '\x8E') //Ä = \x8E
			text[i] = aDots;

		if (text[i] == '\x99') //Ö = \x99
			text[i] = oDots;
	}

	return text;
}
