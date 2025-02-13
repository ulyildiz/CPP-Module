#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _rates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& obj);


};

#endif