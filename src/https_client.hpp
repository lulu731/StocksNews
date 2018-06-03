#ifndef HTTPS_CLIENT_H
#define HTTPS_CLIENT_H

#include <sstream>
#include <stdexcept>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

using boost::asio::ip::tcp;

class HttpException : public std::exception
{
public:
	HttpException(const std::string&);
	const char* what();
private:
	const std::string& m_msg;
};

class HttpReadStatusException : public HttpException 
{	
public:
	HttpReadStatusException(const std::string&);
};

class Client
{
public:
    Client(boost::asio::io_service&,
        boost::asio::ssl::context&,
        const std::string&,
        const std::string&);
    void get_response(std::stringstream&);

private:
    void handle_resolve(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator);
    bool verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx);
    void handle_connect(const boost::system::error_code& err);
    void handle_handshake(const boost::system::error_code& error);
    void handle_write_request(const boost::system::error_code& err);
    void handle_read_status_line(const boost::system::error_code& err);
    void handle_read_headers(const boost::system::error_code& err);
    void handle_read_content(const boost::system::error_code& err);
    tcp::resolver resolver_;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;
    boost::asio::streambuf request_;
    boost::asio::streambuf response_;
    std::stringstream strstream_;
};

#endif