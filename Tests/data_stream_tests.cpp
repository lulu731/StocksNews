#include "../src/data_stream.hpp"

#include <fstream>
#include <iterator>
#include <iostream>

#include "stocks_news_tests.hpp"
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>


struct fixture_dir_stocks {
    fixture_dir_stocks()
    {
	if(!boost::filesystem::exists(dir_stocks)) {
	    boost::filesystem::create_directory(dir_stocks);
	}
	for(auto&& x : boost::filesystem::directory_iterator("../" + dir_stocks + "/")) {
		boost::filesystem::path p;
		p /= dir_stocks;
		p /= x.path().filename();
		boost::filesystem::copy_file(x.path(), p, boost::filesystem::copy_option::overwrite_if_exists);
    }
		boost::filesystem::copy_file(dir_stocks + "/original_stocks_test_database.csv",
			dir_stocks + "/stocks_test_database.csv", boost::filesystem::copy_option::overwrite_if_exists);
	};
};

BOOST_FIXTURE_TEST_SUITE(data_stream_suite, fixture_dir_stocks)

BOOST_AUTO_TEST_CASE(data_stream_test)
{
    data_stream actual("stocks/stocks_test_database.csv");
    int updated_value[5] = {51, 52, 53, 46, 55};
	for( unsigned int i = 0; i  < 5 ; i++ )
	{
		actual.get_stock_name();
		actual.update_news_nb(updated_value[i]);
	}
    actual.close_stream();

    std::ifstream ifs_expected(expected_database);
    std::istream_iterator<char> b_expected(ifs_expected), e_expected;
    std::ifstream ifs_actual(dir_stocks + "/stocks_test_database.csv");
    std::istream_iterator<char> b_actual(ifs_actual), e_actual;
    BOOST_CHECK_EQUAL_COLLECTIONS(b_actual, e_actual, b_expected, e_expected);
}



BOOST_AUTO_TEST_CASE(data_stream_no_update_test)
{
    data_stream actual("stocks/stocks_test_database.csv");
    actual.get_stock_name();
    actual.update_news_nb(51);
    actual.get_stock_name();
    actual.update_news_nb(52);
    actual.get_stock_name();
    std::string str_sn = actual.get_stock_name();
    actual.close_stream();
    BOOST_CHECK_EQUAL(str_sn, "Theolia SA");
}

BOOST_AUTO_TEST_CASE(data_stream_test_update_all)
{
    data_stream actual("stocks/stocks_test_database.csv");
    int updated_value[] = {51, 52, 53, 46, 55, 56, 57, 58, 59, 60};
	unsigned int i = 0;
	while ( !(actual.eof()) )
	{
		actual.get_stock_name();
		//std::cout << actual.get_stock_name() << std::endl;
		actual.update_news_nb(updated_value[i++]);
		//std::cout << actual.eof() << std::endl;
	}
	actual.close_stream();

    std::ifstream ifs_expected(expected_database);
    std::istream_iterator<char> b_expected(ifs_expected), e_expected;
    std::ifstream ifs_actual(dir_stocks + "/stocks_test_database.csv");
    std::istream_iterator<char> b_actual(ifs_actual), e_actual;
    BOOST_CHECK_EQUAL_COLLECTIONS(b_actual, e_actual, b_expected, e_expected);
}

BOOST_AUTO_TEST_SUITE_END()