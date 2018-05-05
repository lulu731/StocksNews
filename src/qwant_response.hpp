#ifndef QWANT_RESPONSE_HPP
#define QWANT_RESPONSE_HPP

#include "https_client.hpp"

#include <sstream>
#include <string>

namespace qwant
{

class QwantResponse
{
public:
    explicit QwantResponse(const std::string&);
    int GetNbNews();

private:
    std::stringstream m_response;
};
}

#endif // QWANT_RESPONSE_HPP
