
#include "https_client.hpp"
#include "json_tree.hpp"
#include "qwant_response.hpp"
#include <iostream>
#include <istream>
#include <string>

using boost::asio::ip::tcp;

qwant::qwant_response::qwant_response()
{
    try {
	boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
	ctx.set_default_verify_paths();

	boost::asio::io_service io_service;
	client c(io_service, ctx, "api.qwant.com", "/api/search/news?q=darty&freshness=week");
	io_service.run();
	c.get_response(response_);

    } catch(std::exception& e) {
	std::cout << "Exception: " << e.what() << "\n";
    };
}

int qwant::qwant_response::get_nb_news()
{
    json_tree json_t_(response_);
    return json_t_.get_int_value("data.result.total");
}