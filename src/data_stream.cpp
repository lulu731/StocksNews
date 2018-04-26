#include "data_stream.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <boost/filesystem.hpp>

data_stream::data_stream(const std::string& database)
	: database_(database), fi_stream_(database, std::ios_base::in), 
	fo_stream_(database + ".tmp", std::ios_base::out | std::ios_base::trunc)
{
	if (!fi_stream_) 
	{
		std::cout << "can't open file" << std::endl; //todo : throw exception
	}	
}

void data_stream::close()
{
	fi_stream_.close();
	fo_stream_.close();
	boost::filesystem::copy_file(database_ + ".tmp", database_, boost::filesystem::copy_option::overwrite_if_exists);
}

void data_stream::update_news_nb(const int nb)
{
	std::string stock_code, stock_name, first_nb, last_nb, inc_rate ;
	int int_first_nb, int_last_nb;
	
	std::getline(fi_stream_, stock_code, ',');
	std::getline(fi_stream_, stock_name, ',');
	std::getline(fi_stream_, first_nb, ',');
	std::getline(fi_stream_, last_nb, ',');
	int_last_nb = std::stoi(last_nb);
	std::getline(fi_stream_, inc_rate);
	
	int_first_nb = int_last_nb;
	int_last_nb = nb;
	fo_stream_ << stock_code << ',' << stock_name << ',' << int_first_nb << ',' << int_last_nb <<  ',' ;
	fo_stream_ << std::setprecision(2) << ((float(int_last_nb) - float(int_first_nb))/float(int_first_nb)) << std::endl;
}


int data_stream::get_news_nb()
{
	return 5;
}
