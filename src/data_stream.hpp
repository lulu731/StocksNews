#ifndef DATA_STREAM_HPP
#define DATA_STREAM_HPP

#include <fstream>
#include <string>

class data_stream
{
public:
    data_stream(const std::string&);
    void close_stream();
    const std::string get_stock_name();
    void update_news_nb(const int);
    int get_news_nb();
	bool eof();

private:
    const std::string _database;
    std::fstream _fi_stream, _fo_stream;
    std::string _stock_code, _stock_name, _first_nb, _last_nb, _inc_rate;
    int _int_first_nb, _int_last_nb;
    bool _stock_updated;
};

#endif // DATA_STREAM_HPP
