#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _dataBase;
		std::ifstream	inputFile;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		bool	openFile(const std::string& fileName);
		void	extractData(void);
		void	parseInput(void);
		
		BitcoinExchange& operator=(const BitcoinExchange& obj);
};

#endif