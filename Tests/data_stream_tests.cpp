#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include "../src/data_stream.hpp"
#include <iterator>
#include <fstream>

const std::string dir_stocks = "stocks";

BOOST_AUTO_TEST_CASE(data_stream_test)
{
	if (!boost::filesystem::exists(dir_stocks))
	{
		boost::filesystem::create_directory(dir_stocks);
	}
	for (auto&& x : boost::filesystem::directory_iterator("../" + dir_stocks +"/"))
	{
		boost::filesystem::path p ;
		p /= dir_stocks;
		p /= x.path().filename();
		boost::filesystem::copy_file(x.path(), p, boost::filesystem::copy_option::overwrite_if_exists);
	}
	boost::filesystem::copy_file(dir_stocks + "/original_stocks_test_database.csv", dir_stocks + "/stocks_test_database.csv", 
		boost::filesystem::copy_option::overwrite_if_exists);
	
	data_stream actual("stocks/stocks_test_database.csv");
	actual.update_news_nb(51);
	actual.update_news_nb(52);
	actual.update_news_nb(53);
	actual.update_news_nb(54);
	actual.update_news_nb(55);
	actual.close();
	
	std::ifstream ifs_expected(dir_stocks + "/expected_stocks_test_database.csv");
	std::istream_iterator<char> b_expected(ifs_expected), e_expected;
	std::ifstream ifs_actual(dir_stocks + "/stocks_test_database.csv");
	std::istream_iterator<char> b_actual(ifs_actual), e_actual;
	BOOST_CHECK_EQUAL_COLLECTIONS(b_actual, e_actual, b_expected, e_expected);
}