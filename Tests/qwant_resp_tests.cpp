#include <boost/test/unit_test.hpp>
#include "../src/qwant_response.hpp"

BOOST_AUTO_TEST_SUITE(qr_suite)//, * boost::unit_test::disabled())

BOOST_AUTO_TEST_CASE(nb_news)
{
	qwant::qwant_response actual;
	BOOST_CHECK_GT(actual.get_nb_news(), 0);
};

BOOST_AUTO_TEST_SUITE_END()
