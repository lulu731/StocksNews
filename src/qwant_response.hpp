#ifndef QWANT_RESPONSE_HPP
#define QWANT_RESPONSE_HPP

#include "https_client.hpp"

#include <sstream>
#include <string>

namespace qwant
{

class qwant_response
{
public:
    qwant_response(const std::string&);
    int get_nb_news();

private:
    std::stringstream response_;
};
}

#endif // QWANT_RESPONSE_HPP
