#include "qwant_response.hpp"

#include <iostream>
#include <istream>
#include <string>

#include "https_client.hpp"
#include "json_tree.hpp"
#include <boost/algorithm/string.hpp>

using boost::asio::ip::tcp;

qwant::QwantResponse::QwantResponse(const std::string& stock_name)
{
    try {
	boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
	ctx.set_default_verify_paths();

	boost::asio::io_service io_service;
	std::string str = stock_name;
	boost::algorithm::replace_all(str, " ", "+");
	Client c(io_service, ctx, "api.qwant.com", "/api/search/news?q=" + str + "&freshness=week");
	io_service.run();
	c.get_response(m_response);
    } catch(std::exception& e) {
	std::cout << "Exception in client.get_response : " << e.what() << "\n";
    };
}

int qwant::QwantResponse::GetNbNews()
{
    JsonTree json_t_(m_response);
    return json_t_.GetIntValue("data.result.total");
}
