#include "stocks_news.hpp"

#include "data_stream.hpp"
#include "qwant_response.hpp"
#include "sorted_stocks.hpp"

#include <iostream>

StocksNews::StocksNews(const std::string& SE) //SE = Stock Exchange
	: m_SEData("stocks/stocks_database_" + SE + ".csv")
{
}

int StocksNews::UpdateNews()
{
	DataStream ds(m_SEData);
	int i(1);
	while (!(ds.EoF ()))
	{
		std::string StocksName(ds.GetStockName ());
		std::cout << i++ << " - updating "  << StocksName << " - ";
		//i = i +1;
		qwant::QwantResponse qr(StocksName);
		int NbNews(qr.GetNbNews());
		std::cout << NbNews ;
		ds.UpdateNewsNb (NbNews);
		std::cout << " - updated" << std::endl;
	};
    ds.CloseStream ();
	return 1; //todo : return error code
}

std::string StocksNews::Results(int NbStocks, ResultType RT)
{
	SortedStocks SStocks(m_SEData, NbStocks, RT);
	std::string StrToReturn;
	std::string str(SStocks.NextStock());
	while (!(str == "No more stock available"))
	{
		StrToReturn += str;
		StrToReturn +="\n";
		str = SStocks.NextStock();
	}
	return StrToReturn;
}
