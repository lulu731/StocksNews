#include "../src/qwant_response.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(qr_suite)

BOOST_AUTO_TEST_CASE(nb_news)
{
	qwant::QwantResponse actual("Darty");
	BOOST_CHECK_GT(actual.GetNbNews(), 0);
};

BOOST_AUTO_TEST_CASE(code_name_with_space)
{
	qwant::QwantResponse actual("Air+France");
	BOOST_CHECK_GT(actual.GetNbNews(), 0);
};

BOOST_AUTO_TEST_SUITE_END()
