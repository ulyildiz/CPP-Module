#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _dataBase;
		std::ifstream	_inputFile;

		void	readInput(void);
		double	dataValue(const std::string& date);
	
		void	checkDate(const std::string& date);
		void	checkValue(const std::string& value, float* fvalue);
		bool	isLeapYear(const int& year);
	
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
