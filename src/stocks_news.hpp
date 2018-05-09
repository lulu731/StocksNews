#ifndef STOCKSNEWS_HPP
#define STOCKSNEWS_HPP

#include <string>

class StocksNews
{
public:
	StocksNews(const std::string&);
	//~StocksNews();
	int UpdateNews();
	std::string Results(int);
private:
	const std::string m_SEData;
};

#endif // STOCKSNEWS_HPP
