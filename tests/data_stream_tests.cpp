#include "../src/data_stream.hpp"

#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <cstdlib>
#include <cstdint>

#include "stocks_news_tests.hpp"
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

struct fixture_dir_stocks
{
    fixture_dir_stocks ()
    {
	if (!boost::filesystem::exists (k_dirStocks))
	    {
		boost::filesystem::create_directory (k_dirStocks);
	    }
	for (auto&& x : boost::filesystem::directory_iterator ("../" + k_dirStocks + "/"))
	    {
		boost::filesystem::path p;
		p /= k_dirStocks;
		p /= x.path ().filename ();
		boost::filesystem::copy_file (x.path (), p, boost::filesystem::copy_option::overwrite_if_exists);
	    }
	boost::filesystem::copy_file (k_dirStocks + "/original_stocks_test_database.csv",
	                              k_dirStocks + "/stocks_test_database.csv",
	                              boost::filesystem::copy_option::overwrite_if_exists);
    };
};

BOOST_FIXTURE_TEST_SUITE (data_stream_suite, fixture_dir_stocks)

BOOST_AUTO_TEST_CASE (data_stream_test)
{
    DataStream actual ("stocks/stocks_test_database.csv");
    int updated_value[6] = {51, 52, 53, 46, 55, 49};
    for (unsigned int i = 0; i < 6; i++)
	{
	    actual.GetStockName ();
	    actual.UpdateNewsNb (updated_value[i]);
	}
    actual.CloseStream ();

    std::ifstream ifs_expected (k_expectedDatabase);
    std::istream_iterator<char> b_expected (ifs_expected), e_expected;
    std::ifstream ifs_actual (k_dirStocks + "/stocks_test_database.csv");
    std::istream_iterator<char> b_actual (ifs_actual), e_actual;
    BOOST_CHECK_EQUAL_COLLECTIONS (b_actual, e_actual, b_expected, e_expected);
}

BOOST_AUTO_TEST_CASE (data_stream_no_update_test)
{
    DataStream actual ("stocks/stocks_test_database.csv");
    actual.GetStockName ();
    actual.UpdateNewsNb (51);
    actual.GetStockName ();
    actual.UpdateNewsNb (52);
    actual.GetStockName ();
    std::string str_sn = actual.GetStockName ();
    actual.CloseStream ();
    BOOST_CHECK_EQUAL (str_sn, "Theolia SA");
}

BOOST_AUTO_TEST_CASE (data_stream_test_update_all)
{
    DataStream actual ("stocks/stocks_test_database.csv");
    int updated_value[] = {51, 52, 53, 46, 55, 49, 57, 58, 59, 60};
    unsigned int i = 0;
    while (!(actual.EoF()))
	{
	    actual.GetStockName();
	    actual.UpdateNewsNb(updated_value[i++]);
	}
    actual.CloseStream();

    std::ifstream ifs_expected (k_expectedDatabase);
    std::istream_iterator<char> b_expected (ifs_expected), e_expected;
    std::ifstream ifs_actual (k_dirStocks + "/stocks_test_database.csv");
    std::istream_iterator<char> b_actual (ifs_actual), e_actual;
    BOOST_CHECK_EQUAL_COLLECTIONS (b_actual, e_actual, b_expected, e_expected);
}

BOOST_AUTO_TEST_CASE (data_stream_test_from_zero)
{
	DataStream actual ("stocks/stocks_with_zero_test_database.csv");
    while (!(actual.EoF()))
	{
	    actual.GetStockName();
	    actual.UpdateNewsNb(2);
	}
    actual.CloseStream();
	std::fstream Stream("stocks/stocks_with_zero_test_database.csv");
	float flRate;
	std::string str;
	std::getline(Stream, str, ',');
	std::getline(Stream, str, ',');
	std::getline(Stream, str, ',');
	std::getline(Stream, str, ',');
	std::getline(Stream, str);
	char* end;
	flRate = std::strtof(str.c_str(), &end);
	BOOST_CHECK_EQUAL(flRate,  std::numeric_limits<float>::infinity());
}

BOOST_AUTO_TEST_CASE (data_stream_test_from_and_update_zero)
{
	DataStream actual ("stocks/stocks_with_zero_test_database.csv");
    while (!(actual.EoF()))
	{
	    actual.GetStockName();
	    actual.UpdateNewsNb(0);
	}
    actual.CloseStream();
	std::fstream Stream("stocks/stocks_with_zero_test_database.csv");
	float Rate;
	std::string str;
	std::getline(Stream, str, ',');
	std::getline(Stream, str, ',');
	std::getline(Stream, str, ',');
	std::getline(Stream, str, ',');
	std::getline(Stream, str);
	char* end;
	Rate = std::strtof(str.c_str(), &end);
	BOOST_CHECK_EQUAL(Rate, 0);
}

BOOST_AUTO_TEST_SUITE_END ()