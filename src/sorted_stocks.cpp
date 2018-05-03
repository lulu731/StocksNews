#include "sorted_stocks.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

sorted_stocks::sorted_stocks(const std::string& data_base_name, int stocks_nb, bool up)
{
    std::fstream istream(data_base_name, std::ios_base::in);
    _no_more_stocks = "No more stock available";
    while(!(istream.eof())) {
	std::string line;
	std::getline(istream, line, '\n');
	std::istringstream line_stream(line);
	std::string str;
	std::getline(line_stream, str, ',');
	std::getline(line_stream, str, ',');
	std::getline(line_stream, str, ',');
	std::getline(line_stream, str, ','); // gets increasing rate
	std::getline(line_stream, str);
	_mmap_sorted_stocks.insert(std::make_pair(strtof(str.c_str(), NULL), line));
	if(int(_mmap_sorted_stocks.size()) > stocks_nb) {
	    auto it = _mmap_sorted_stocks.end();
	    --it;
	    _mmap_sorted_stocks.erase(it);
	}
    }
    _it_sorted_stocks = _mmap_sorted_stocks.begin();
}

const std::string& sorted_stocks::next_stock()
{
    if(_it_sorted_stocks != _mmap_sorted_stocks.end()) {
	return _it_sorted_stocks++->second;
    } else
	return _no_more_stocks;
}
