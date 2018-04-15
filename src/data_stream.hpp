#ifndef DATA_STREAM_HPP
#define DATA_STREAM_HPP

#include <string>
#include <fstream>

class data_stream
{
public:
	data_stream(const std::string&);
	void close();
	void update_news_nb(const int);
	int get_news_nb();
private:
	std::fstream fi_stream_, fo_stream_;
	const std::string database_;
	int output_pos = 0 ;
};

#endif // DATA_STREAM_HPP
