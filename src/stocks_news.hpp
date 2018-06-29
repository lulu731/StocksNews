#ifndef STOCKSNEWS_HPP
#define STOCKSNEWS_HPP

#include "sorted_stocks.hpp"

#include <string>

class StocksNews
{
public:
	StocksNews(const std::string&);
	//~StocksNews();
	int UpdateNews();
	std::string Results(int, ResultType);
private:
	const std::string m_SEData;
};

#endif // STOCKSNEWS_HPP
