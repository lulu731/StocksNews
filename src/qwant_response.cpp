#include "qwant_response.hpp"

#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>

#include "https_client.hpp"
#include "json_tree.hpp"
#include <boost/algorithm/string.hpp>

using boost::asio::ip::tcp;

qwant::QwantResponse::QwantResponse(const std::string& stock_name) :
	m_stockName (stock_name)
{
}

int qwant::QwantResponse::GetNbNews()
{
    const unsigned int MaxNbRetry(3);
	for( unsigned int i = 0; i  < MaxNbRetry; i++ )
	{
		try {
			boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
			ctx.set_default_verify_paths();
			boost::asio::io_service io_service;
			Client c(io_service, ctx, "api.qwant.com", "/api/search/news?q=" + m_stockName + "&freshness=week");
			io_service.run();
			c.get_response(m_response);
			JsonTree json_t_(m_response);
			return json_t_.GetIntValue("data.result.total");
		}
		catch (HttpReadStatusException& e)
		{
			boost::algorithm::replace_all(m_stockName, " ", "+");
			boost::algorithm::replace_all(m_stockName, "à", "a");
			boost::algorithm::replace_all(m_stockName, "é", "e");
			boost::algorithm::replace_all(m_stockName, "è", "e");
			boost::algorithm::replace_all(m_stockName, "ê", "e");
			boost::algorithm::replace_all(m_stockName, "ë", "e");
			boost::algorithm::replace_all(m_stockName, "î", "i");
			boost::algorithm::replace_all(m_stockName, "ô", "o");
			boost::algorithm::replace_all(m_stockName, "ö", "o");
			boost::algorithm::replace_all(m_stockName, "ù", "u");
			boost::algorithm::replace_all(m_stockName, "û", "u");
			boost::algorithm::replace_all(m_stockName, "ü", "u");
			return GetNbNews();
		}
		catch (std::exception& e)
		{
			std::cout << "Unmanaged exception : try number " <<  i+1;
		}
	}
	return -1;
}
