#ifndef SORTED_STOCKS_HPP
#define SORTED_STOCKS_HPP

#include <map>
#include <string>

class sorted_stocks
{
public:
    sorted_stocks(const std::string&, int, bool = true);
    const std::string& next_stock();

private:
    std::multimap<float, std::string, std::greater<float>> _mmap_sorted_stocks;
    std::multimap<float, std::string, std::greater<float>>::iterator _it_sorted_stocks;
    std::string _no_more_stocks;
};

#endif // SORTED_STOCKS_HPP
