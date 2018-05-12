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
	while (!(ds.EoF ()))
	{
	    std::cout << ds.GetStockName();
		qwant::QwantResponse qr(ds.GetStockName ());
	    ds.UpdateNewsNb (qr.GetNbNews());
	};
    ds.CloseStream ();
	return 1; //todo : return error code
}

std::string StocksNews::Results(int NbStocks)
{
	SortedStocks SStocks(m_SEData, NbStocks);
	std::string StrToReturn;
	std::string str(SStocks.NextStock());
	while (!(str == "No more stock available"))
	{
		StrToReturn += str;
		str = SStocks.NextStock();
	}
	return StrToReturn;
}
