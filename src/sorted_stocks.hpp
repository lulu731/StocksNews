#ifndef SORTED_STOCKS_HPP
#define SORTED_STOCKS_HPP

#include <map>
#include <string>

class SortedStocks
{
public:
    SortedStocks(const std::string&, int);
    const std::string& NextStock();

private:
    std::multimap<float, std::string, std::greater<float>> m_mmapSortedStocks;
    std::multimap<float, std::string, std::greater<float>>::iterator m_itSortedStocks;
    std::string m_noMoreStocks;
};

#endif // SORTED_STOCKS_HPP
