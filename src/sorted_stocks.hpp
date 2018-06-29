#ifndef SORTED_STOCKS_HPP
#define SORTED_STOCKS_HPP

#include <map>
#include <string>

enum ResultType {
	MaxRate,
	MaxNumbers
};

class SortedStocks
{
public:
    SortedStocks(const std::string&, const int, const ResultType = MaxRate);
    const std::string& NextStock();
private:
    std::multimap<float, std::string, std::greater<float>> m_mmapSortedStocks;
    std::multimap<float, std::string, std::greater<float>>::iterator m_itSortedStocks;
    std::string m_noMoreStocks;
	void SortByMaxRate(const std::string&, const int);
	void SortByMaxNumbers(const std::string&, const int);
};

#endif // SORTED_STOCKS_HPP
