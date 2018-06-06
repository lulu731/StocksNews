#include "data_stream.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

#include <boost/filesystem.hpp>

DataStream::DataStream(const std::string& database)
    : m_database(database)
    , m_fiStream(database, std::ios_base::in)
    , m_foStream(database + ".tmp", std::ios_base::out | std::ios_base::trunc)
{
    m_stockName = "";
    m_stockUpdated = false;
    if(!m_fiStream) {
	std::cout << "can't open file" << std::endl; // todo : throw exception
    }
	m_stockUpdated = true;
}

void DataStream::CloseStream()
{
    m_fiStream.close();
    m_foStream.close();
    boost::filesystem::copy_file(m_database + ".tmp", m_database, boost::filesystem::copy_option::overwrite_if_exists);
}

void DataStream::UpdateNewsNb(const int nb)
{
    std::getline(m_fiStream, m_firstNb, ',');
    std::getline(m_fiStream, m_lastNb, ',');
    m_intLastNb = std::stoi(m_lastNb);
    std::getline(m_fiStream, m_incRate,'\n');

    m_intFirstNb = m_intLastNb;
    m_intLastNb = nb;
    m_foStream << m_stockCode << ',' << m_stockName << ',' << m_intFirstNb << ',' << m_intLastNb << ',';
	float flRate;
	if (m_intFirstNb == 0 && nb == 0)
		{
			flRate = 0;
		} else {
		flRate = (float(m_intLastNb - m_intFirstNb) / m_intFirstNb) ;
		} ;
	m_foStream << std::setprecision(2) <<  flRate << std::endl;
	
    m_stockUpdated = true;
	m_stockName = GetStockName();
}

const std::string DataStream::GetStockName()
{
	if (m_stockUpdated)
	{
		std::getline(m_fiStream, m_stockCode, ',');
		std::getline(m_fiStream, m_stockName, ',');
		m_stockUpdated = false;
    };
    return m_stockName;
}

bool DataStream::EoF()
{
	return m_fiStream.eof();
}
