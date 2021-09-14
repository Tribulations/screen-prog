#include "Date.h"
#include "Stock.h"
#include "functions.h"

int main()
{
	std::fstream file;
	vector<Stock> stocks;
	Stock stock;
	vector<string> fileNames;

	readFileNames(fileNames); // puts all the filenames in the scrapedatabase folder in vector<str> filenames

	//string pFPath = "C:\\Users\\Jocke\\Desktop\\Stock\\ScrapeDatabase\\"; // windows
	string pFPath = "/home/pi/sharedFolder/Scraping/database/"; // linux

	for (int i = 0; i < fileNames.size(); ++i)
	{
		//cout << "pos : " << i << endl;
		stock = readCSV(pFPath + fileNames.at(i) );
		stock.printTradingDays();
		//stock.checkBullishEngulfing();
		//stock.checkHighVol();
		stocks.push_back(stock);
	}
	file.close();
	getchar();

	return 0;
}
//Old main function
/*Old main function
int main()
{
	// This is the program that runs thorugh all the stocks and prints their values

	std::fstream file;

	//std::fstream file2; // write all the data from all the shares to this file
	//file2.open("C:\\Users\\Jocke\\Desktop\\shares.txt", std::ios::out);
	//if (file2.is_open())
	//	cout << "open\n";
	//else
	//	cout << "not open\n";


	//string fpath = "A3 ALLM�NNA IT- OCH TELEKOM..csv";

	vector<Stock> stocks;
	TradingDay tradingDay;

	Stock stock;

	vector<string> fileNames;
	readFileNames(fileNames); // puts all the filenames in the scrapedatabase folder in vector<str> filenames
	//fileNames.at(0)[7] =

	string pFPath = "C:\\Users\\Jocke\\Desktop\\Stock\\ScrapeDatabase\\"; // windows
	//string pFPath = "/home/jocke/Scraping/ScrapeDatabase/"; // linux

	// prints all the filenames from fileNames vector

	//fileNames.at(0)[7] = '\u00C4';
	//char test = fileNames.at(0)[7];

	//cout << int(test) << endl << endl;

	for (int i = 0; i < fileNames.size(); ++i)
	{
		//readCSV(file, stocks, tradingDay, pFPath + fileNames.at(i));
		//readCSV(file, stocks, tradingDay, "C:\\Users\\Jocke\\Desktop\\Stock\\ScrapeDatabase\\A3 ALLM�NNA IT- OCH TELEKOM..csv"); // g�r att �ppna filen med denna
		//stocks.at(i).printTradingDays();

		stock = readCSV(pFPath + fileNames.at(i) ); // why can the formatSpecialChar() only be run from here and not from whitin the readCSV() ??
		//stock.printTradingDays();
		stock.checkBullishEngulfing();
		cout << "pos : " << i << endl;
		//stock.checkHighVol();
		// print the stock data to file


		//file2 << stock.getTradingDays() << endl;
		stocks.push_back(stock);
		//cout << endl;
	}
	//cout << "klart!";
	//cout << stocks.at(380).getStockName() << endl;
	//stocks.at(380).printTradingDay( stocks.at(380).getTradingDay( stocks.at( 380 ).getTotalTradingDays() - 1 ) ); // prints a single trading day
	file.close();
	//file2.close();

	getchar();

	return 0;
}


*/

//*************************************************////////////////////////***********************
//*************************************************/////////YEAH///////////***********************
//*************************************************////////////////////////***********************

/*
Read and check all the code and improve it before doing any new functions or code

*********TO CODE****
Funktion som bara tar ut namnet p� aktien som ska sparas in Stockname namnet. allts� t.ex. C:\sjdfsj\\>JAFjs\\AAK.csv
s� ska bara AAK sparas ur denna string.
_______
Fixa funktion som returnerar antal csv filer allts� antal akiter att l�sa? Beh�vs detta?
_______
Endast Win problem f�ljande:
Fixa s� att de tror det �r de 2 sista raderna i dir.txt filen inte blir inl�sta till fileNAmes vectorn d� dessa rader bara �r skr�p.
________
Fixa funktion som uppt�cker aktie namn med bokst�verna �� eller � och g�r n�t? Fast det g�r ju �nd� inte f�r filerna i mappen ScrapeDatabse heter ju namn med boks�verna � � �???
Hur g�ra ? Jo fixa en funktion som formaterar namnet innan det stoppas in i file.open()
________
Formatera texten kolumnerna p� datan som skrivs ut f�r varje aktie s� det blir snyggare. typ anv�nda setf eller vad den heter p� cout
// eg. datum setf n�gra rader sen close sen mellanrum ja allts� s� hahahhaehhwhwh

****** Aktuella Fel ******
Fixa s� att alla filer kan �ppnas. Just nu kan inte filer som har ��� �ppnas i detta program men det funkar n�r jag testat annars. Varf�r?

G�r att �ppna alla csv filer �ven de med ��� men...... det g�r ej d� filnamnet tas fr�n fileNames vectorn skumt!!!!!
namnet i filenames vectorn beh�ller sitt � t.ex. men om man skriver det direkt i file.open() t.ex. s� f�r�ndas � ???


Kolla ifall en bullish engulfing funkar genom att kolla emd if ifall f�ljande dag �ppnade h�gre och sedan n�sta dag och n�sta och ifall
det g�r upp mest s� typ ska just den bullish engulfing med dom inst�llningran ges po�ng. Och sedan ska de inst�llningar av varje enulf eller highvol och likande
anv�ndas mer och mer och �ven variera inst�llningar och sedan ska programmet utv�rdera och betygs�tta det utf�rda beteendet. Bra betenneded bel�nas och utf�rs oftare
medan d�ligtr betende ges d�lig po�ng och det ska allts� inte upprepas. Men kanske ibaldn f�r att se om det kanske funkar men det ges alltid ett betyg.

Kan g�ra en m�ngd olika funktioner av varje? Eller typ ha funktioner som slump�ssigt genrerar argument typ till en bullish engulfing funktion? Och sedan betygss�tt
ett antal variabler efter hur bra det lyckades. Typ hur m�nga akiter hittadas, hur m�nga av de aktier som hittades som gick upp �hh jag vet ej nu
men mkt ska testas och sedan sparas s� att programmet kan utveklas av att testa mer och mer aktier.

*/
