#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _rates() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _rates(copy._rates) { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this != &obj)
		this->_rates = obj._rates;
	return (*this);
}



