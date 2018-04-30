#include "data_stream.hpp"
#include <boost/filesystem.hpp>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

data_stream::data_stream(const std::string& database)
    : _database(database)
    , _fi_stream(database, std::ios_base::in)
    , _fo_stream(database + ".tmp", std::ios_base::out | std::ios_base::trunc)
{
    _stock_name = "";
    _stock_updated = false;
    if(!_fi_stream) {
	std::cout << "can't open file" << std::endl; // todo : throw exception
    }
}

void data_stream::close_stream()
{
    _fi_stream.close();
    _fo_stream.close();
    boost::filesystem::copy_file(_database + ".tmp", _database, boost::filesystem::copy_option::overwrite_if_exists);
}

void data_stream::update_news_nb(const int nb)
{
    std::getline(_fi_stream, _first_nb, ',');
    std::getline(_fi_stream, _last_nb, ',');
    _int_last_nb = std::stoi(_last_nb);
    std::getline(_fi_stream, _inc_rate);

    _int_first_nb = _int_last_nb;
    _int_last_nb = nb;
    _fo_stream << _stock_code << ',' << _stock_name << ',' << _int_first_nb << ',' << _int_last_nb << ',';
    _fo_stream << std::setprecision(2) << (float(_int_last_nb - _int_first_nb) / _int_first_nb) << std::endl;
    _stock_updated = true;
}

const std::string data_stream::get_stock_name()
{
    if(_stock_name.empty() || _stock_updated) {
	std::getline(_fi_stream, _stock_code, ',');
	std::getline(_fi_stream, _stock_name, ',');
	_stock_updated = false;
    };
    return _stock_name;
}

int data_stream::get_news_nb()
{
    return 5;
}

sorted_stocks data_stream::sort_stocks(const int out_nb, const bool up)
{
    // return _sorted_stocks;
}
