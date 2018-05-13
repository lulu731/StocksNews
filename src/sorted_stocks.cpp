#include "sorted_stocks.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

SortedStocks::SortedStocks(const std::string& data_base_name, int stocks_nb, bool up)
{
    std::fstream istream(data_base_name, std::ios_base::in);
    m_noMoreStocks = "No more stock available";
    
	std::string line;
	std::getline(istream, line, '\n');
	while(!(istream.eof())) 
	{
	std::istringstream line_stream(line);
	std::string str;
	std::getline(line_stream, str, ',');
	std::getline(line_stream, str, ',');
	std::getline(line_stream, str, ',');
	std::getline(line_stream, str, ','); // gets increasing rate
	std::getline(line_stream, str);
	m_mmapSortedStocks.insert(std::make_pair(strtof(str.c_str(), nullptr), line));
	if(int(m_mmapSortedStocks.size()) > stocks_nb) 
	{
	    auto it = m_mmapSortedStocks.end();
	    --it;
	    m_mmapSortedStocks.erase(it);
	}
	std::getline(istream, line, '\n');
    }
    m_itSortedStocks = m_mmapSortedStocks.begin();
}

const std::string& SortedStocks::NextStock()
{
    if(m_itSortedStocks != m_mmapSortedStocks.end()) {
	return m_itSortedStocks++->second;
    } else
	return m_noMoreStocks;
}