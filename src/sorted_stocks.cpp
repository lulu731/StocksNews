#include "sorted_stocks.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

SortedStocks::SortedStocks(const std::string& data_base_name, const int stocks_nb, const ResultType rt)
{
    m_noMoreStocks = "No more stock available";
    if (rt == MaxRate) {
		SortByMaxRate(data_base_name, stocks_nb);
	} else {
		if (rt == MaxNumbers) {
			SortByMaxNumbers(data_base_name, stocks_nb);
		}
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

void SortedStocks::SortByMaxRate(const std::string& data_base_name, const int stocks_nb)
{
   std::fstream istream(data_base_name, std::ios_base::in);
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
		if (!(str == "inf"))
		{
			m_mmapSortedStocks.insert(std::make_pair(strtof(str.c_str(), nullptr), line));
			if(int(m_mmapSortedStocks.size()) > stocks_nb)
			{
				auto it = m_mmapSortedStocks.end();
				--it;
				m_mmapSortedStocks.erase(it);
			}
		}
			std::getline(istream, line, '\n');
    }
}

void SortedStocks::SortByMaxNumbers(const std::string& data_base_name, const int stocks_nb)
{
	std::map<int, std::multimap<float, std::string, std::greater<float>>*, std::greater<int>> AMap;
	int NbItems(0);
	std::string line;
	std::fstream istream(data_base_name, std::ios_base::in);
 	std::getline(istream, line, '\n');
	while(!(istream.eof())) 
	{	
		//std::cout << "in while loop \n";
		std::istringstream line_stream(line);
		std::string str;
		std::getline(line_stream, str, ',');
		std::getline(line_stream, str, ',');
		std::getline(line_stream, str, ',');

		const int NewsNbre(std::stoi(str.c_str()));
		std::getline(line_stream, str, ','); // gets increasing rate
		std::getline(line_stream, str);
		const float Afloat(strtof(str.c_str(), nullptr));

		if (NbItems < stocks_nb){
			if (!(str == "inf") && (Afloat > 0)){	
				if (AMap.find(NewsNbre) == AMap.end()) {
					AMap.insert(std::pair<int, std::multimap<float, std::string, std::greater<float>>*>
						(NewsNbre, new std::multimap<float, std::string, std::greater<float>>));
				}
				AMap[NewsNbre]->insert(std::make_pair(Afloat, line));
				++NbItems;
			}
		} else {
			if (!(str == "inf") && (Afloat > 0)){	
				auto it = AMap.end(); //(*it) is a pointer to a map
				
				if (NewsNbre >= (*(--it)).first) {
					if (AMap.find(NewsNbre) == AMap.end()) {
						AMap.insert(std::pair<int, std::multimap<float, std::string, std::greater<float>>*>
							(NewsNbre, new std::multimap<float, std::string, std::greater<float>>));
					}
					auto it2 = (*((*it).second)).end();
					
					if (Afloat > (*(--it2)).first) {
						AMap[NewsNbre]->erase(it2);
						AMap[NewsNbre]->insert(std::make_pair(Afloat, line));
					}
				}
			}
		}
		std::getline(istream, line, '\n');
	}	

	for (std::map<int, std::multimap<float, std::string, std::greater<float>>*>::iterator it = AMap.begin(); it!=AMap.end(); ++it) {
		if (int(m_mmapSortedStocks.size()) < stocks_nb)
			{m_mmapSortedStocks.insert((*(it->second)).begin(), (*(it->second)).end());}
		delete (it->second);
	}

	while (int(m_mmapSortedStocks.size()) > stocks_nb){
		auto it = m_mmapSortedStocks.end();
		--it;
		m_mmapSortedStocks.erase(it);
	}
}