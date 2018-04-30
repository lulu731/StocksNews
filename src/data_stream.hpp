#ifndef DATA_STREAM_HPP
#define DATA_STREAM_HPP

#include <fstream>
#include <map>
#include <string>

class sorted_stocks
{
public:
    // sorted_stocks(const int);
    // add_stock(const std::string&);
private:
    const int _max_nb_stocks;
    // std::multimap _mm;
};

class data_stream
{
public:
    data_stream(const std::string&);
    void close_stream();
    const std::string get_stock_name();
    void update_news_nb(const int);
    int get_news_nb();
    sorted_stocks sort_stocks(const int, const bool = true);

private:
    const std::string _database;
    std::fstream _fi_stream, _fo_stream;
    std::string _stock_code, _stock_name, _first_nb, _last_nb, _inc_rate;
    int _int_first_nb, _int_last_nb;
    bool _stock_updated;
    // sorted_stocks _sorted_stocks;
};

#endif // DATA_STREAM_HPP
