#include "../src/sorted_stocks.hpp"
#include "stocks_news_tests.hpp"
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>

struct fixture_copy_expected_database {
    fixture_copy_expected_database()
    {
	if(!boost::filesystem::exists(k_expectedDatabase)) {
	    boost::filesystem::copy_file(
	        "../" + k_expectedDatabase, k_expectedDatabase);
	}
    }
};

BOOST_FIXTURE_TEST_SUITE(sorted_stocks_suite, fixture_copy_expected_database)

BOOST_AUTO_TEST_CASE(sort_stocks_by_maxrate)
{
    SortedStocks actual(k_expectedDatabase, 3);
    const std::string expected_sorted_stocks[3] = { "KN.PA,Natixis,49,55,0.12", "TEO.PA,Theolia SA,50,53,0.06",
	"ACA.PA,Credit Agricole,50,52,0.04" };
    for(auto& str : expected_sorted_stocks) {
	BOOST_CHECK_EQUAL(str, actual.NextStock());
    }
}

BOOST_AUTO_TEST_CASE(sort_stocks_by_maxnumber)
{
    SortedStocks actual(k_expectedDatabase, 4, MaxNumbers);
    const std::string expected_sorted_stocks[4] = { "KN.PA,Natixis,49,55,0.12", "TEO.PA,Theolia SA,50,53,0.06", 
		"ACA.PA,Credit Agricole,50,52,0.04", "FTE.PA,France Telecom,50,51,0.02"};
    for(auto& str : expected_sorted_stocks) {
	BOOST_CHECK_EQUAL(str, actual.NextStock());
    }
}

BOOST_AUTO_TEST_CASE(sort_stocks_no_request)
{
    SortedStocks actual(k_expectedDatabase, 0);
    BOOST_CHECK_EQUAL("No more stock available", actual.NextStock());
}

BOOST_AUTO_TEST_CASE(sort_stocks_with_neg_val)
{
	if(!boost::filesystem::exists("stocks/stocks_test_database_with_neg_val.csv")) {
	    boost::filesystem::copy_file(
	        "../stocks/stocks_test_database_with_neg_val.csv", "stocks/stocks_test_database_with_neg_val.csv",
			boost::filesystem::copy_option::overwrite_if_exists);
	}
	SortedStocks actual("stocks/stocks_test_database_with_neg_val.csv", 5);
    const std::string expected_sorted_stocks[5] = { "KN.PA,Natixis,49,55,0.12", "TEO.PA,Theolia SA,50,53,0.06",
	"ACA.PA,Credit Agricole,50,52,0.04", "FTE.PA,France Telecom,50,51,0.02", "FP.PA,Total SA,50,46,-0.08" };
    for(auto& str : expected_sorted_stocks) {
	BOOST_CHECK_EQUAL(str, actual.NextStock());
    }
}

BOOST_AUTO_TEST_SUITE_END()