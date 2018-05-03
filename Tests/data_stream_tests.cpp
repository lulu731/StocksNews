#include "../src/data_stream.hpp"
#include "stocks_news_tests.hpp"
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <iterator>

struct fixture_dir_stocks {
    fixture_dir_stocks()
    {
	if(!boost::filesystem::exists(dir_stocks)) {
	    boost::filesystem::create_directory(dir_stocks);
	}
    }
};

BOOST_FIXTURE_TEST_SUITE(data_stream_suite, fixture_dir_stocks)

BOOST_AUTO_TEST_CASE(data_stream_test)
{
    for(auto&& x : boost::filesystem::directory_iterator("../" + dir_stocks + "/")) {
	boost::filesystem::path p;
	p /= dir_stocks;
	p /= x.path().filename();
	boost::filesystem::copy_file(x.path(), p, boost::filesystem::copy_option::overwrite_if_exists);
    }
    boost::filesystem::copy_file(dir_stocks + "/original_stocks_test_database.csv",
        dir_stocks + "/stocks_test_database.csv", boost::filesystem::copy_option::overwrite_if_exists);

    data_stream actual("stocks/stocks_test_database.csv");
    actual.get_stock_name();
    actual.update_news_nb(51);
    actual.get_stock_name();
    actual.update_news_nb(52);
    std::string str_sn = actual.get_stock_name();
    BOOST_CHECK_EQUAL(str_sn, "Theolia SA");
    actual.update_news_nb(53);
    actual.get_stock_name();
    actual.update_news_nb(46);
    actual.get_stock_name();
    actual.update_news_nb(55);
    actual.close_stream();

    std::ifstream ifs_expected(expected_database);
    std::istream_iterator<char> b_expected(ifs_expected), e_expected;
    std::ifstream ifs_actual(dir_stocks + "/stocks_test_database.csv");
    std::istream_iterator<char> b_actual(ifs_actual), e_actual;
    BOOST_CHECK_EQUAL_COLLECTIONS(b_actual, e_actual, b_expected, e_expected);
}

BOOST_AUTO_TEST_CASE(data_stream_no_update_test)
{
    boost::filesystem::copy_file(dir_stocks + "/original_stocks_test_database.csv",
        dir_stocks + "/stocks_test_database.csv", boost::filesystem::copy_option::overwrite_if_exists);

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

BOOST_AUTO_TEST_SUITE_END()