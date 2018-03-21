#ifndef QWANT_RESPONSE_HPP
#define QWANT_RESPONSE_HPP

#include "https_client.hpp"
#include <sstream>

namespace qwant
{

class qwant_response
{
public:
    qwant_response();
    int get_nb_news();

private:
    std::stringstream response_;
};
}

#endif // QWANT_RESPONSE_HPP
