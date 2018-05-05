#ifndef DATA_STREAM_HPP
#define DATA_STREAM_HPP

#include <fstream>
#include <string>

class DataStream
{
public:
    explicit DataStream(const std::string&);
    void CloseStream();
    const std::string GetStockName();
    void UpdateNewsNb(const int);
    bool EoF();

private:
    const std::string m_database;
    std::fstream m_fiStream, m_foStream;
    std::string m_stockCode, m_stockName, m_firstNb, m_lastNb, m_incRate;
    int m_intFirstNb, m_intLastNb;
    bool m_stockUpdated;
};

#endif // DATA_STREAM_HPP
