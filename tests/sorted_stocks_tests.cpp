#include "../src/sorted_stocks.hpp"
#include "stocks_news_tests.hpp"
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

struct fixture_copy_expected_database {
    fixture_copy_expected_database()
    {
	if(!boost::filesystem::exists(k_expectedDatabase)) {
	    boost::filesystem::copy_file(
	        "../" + k_expectedDatabase, k_expectedDatabase, boost::filesystem::copy_option::overwrite_if_exists);
	};
    };
};

BOOST_FIXTURE_TEST_SUITE(sorted_stocks_suite, fixture_copy_expected_database)

BOOST_AUTO_TEST_CASE(sort_stocks_up)
{
    SortedStocks actual(k_expectedDatabase, 3);
    const std::string expected_sorted_stocks[3] = { "KN.PA,Natixis,49,55,0.12", "TEO.PA,Theolia SA,50,53,0.06",
	"ACA.PA,Credit Agricole,50,52,0.04" };
    for(auto& str : expected_sorted_stocks) {
	BOOST_CHECK_EQUAL(str, actual.NextStock());
    }
}

BOOST_AUTO_TEST_CASE(sort_stocks_no_request)
{
    SortedStocks actual(k_expectedDatabase, 0);
    BOOST_CHECK_EQUAL("No more stock available", actual.NextStock());
}

BOOST_AUTO_TEST_SUITE_END()