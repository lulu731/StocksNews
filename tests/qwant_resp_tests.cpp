#include "../src/qwant_response.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(qr_suite)

BOOST_AUTO_TEST_CASE(nb_news)
{
	qwant::QwantResponse actual("Darty");
	BOOST_CHECK_GT(actual.GetNbNews(), -1);
};

BOOST_AUTO_TEST_CASE(code_name_with_space)
{
	qwant::QwantResponse actual("Air France");
	BOOST_CHECK_GT(actual.GetNbNews(), -1);
};

BOOST_AUTO_TEST_CASE(code_name_with_accent)
{
	qwant::QwantResponse actual("Société des Autoroutes Paris-Rhin-Rhône");
	qwant::QwantResponse expected("Societe+des+Autoroutes+Paris+Rhin+Rhone");
	BOOST_CHECK_EQUAL(actual.GetNbNews(), expected.GetNbNews());
};

BOOST_AUTO_TEST_CASE(code_name_without_accent)
{
	qwant::QwantResponse actual("Societe des Autoroutes Paris-Rhin-Rhone");
	BOOST_CHECK_GT(actual.GetNbNews(), -1);
};

BOOST_AUTO_TEST_SUITE_END()
