#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _dataBase(copy._dataBase) { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this != &obj)
		this->_dataBase = obj._dataBase;
	return (*this);
}

bool	BitcoinExchange::openFile(const std::string& fileName)
{
	this->inputFile.open(fileName.c_str(), std::ios::in);
	if (!this->inputFile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::extractData(void)
{
	std::string	line;
	std::string	key;
	double		value;

	std::getline(this->inputFile, line);
	while (std::getline(this->inputFile, line))
	{
		key = line.substr(0, line.find(','));
		value = std::strtod(line.substr(line.find(',') + 1).c_str(), NULL);
		this->_dataBase.insert(std::pair<std::string, double>(key, value));
	}
	
	inputFile.close();
	if (inputFile.rdstate() == std::ios::failbit)
	{
		std::cerr << "Error: could not close file." << std::endl;
		return ;
	}
}

void	BitcoinExchange::parseInput(void)
{
	std::string	line;

	std::getline(this->inputFile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: invalid file format." << std::endl;
		return ;
	}
	this->readInput();
	inputFile.close();
	if (inputFile.rdstate() == std::ios::failbit)
	{
		std::cerr << "Error: could not close file." << std::endl;
		return ;
	}
}

void	BitcoinExchange::readInput(void)
{
	std::string	line;

	while (std::getline(this->inputFile, line))
	{
		if (!this->checkDate(line))
		{
			std::cerr << std::endl;
			continue ;
		}
		if (!this->checkValue(line))
		{
			std::cerr << std::endl;
			continue ;
		}
	}
}

bool	BitcoinExchange::checkDate(const std::string& date)
{
	int	dashcount = 0;
	
	for (std::string::size_type i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			return (std::cerr << "Error: bad input => " << date, false);
		if (date[i] == '-')
			dashcount++;
	}
	if (dashcount != 2)
		return (std::cerr << "Error: bad input => " << date, false);

	std::string	year = date.substr(0, date.find('-'));
	std::string	month = date.substr(date.find('-') + 1, date.rfind('-') - date.find('-') - 1);
	std::string	day = date.substr(date.rfind('-') + 1);

	if (month.size() != 2 || month < "01" || month > "12")
		return (std::cerr << "Error: bad input => " << date, false);

	if (std::atoi(year.c_str()) < 0)
		return (std::cerr << "Error: bad input => " << date, false);

	if (!checkDay(day))
		return (std::cerr << "Error: bad input => " << date, false);

	return (true);
}

bool	BitcoinExchange::isLeapYear(const std::string& year)
{
	if ((std::atoi(year.c_str()) % 4 == 0 && std::atoi(year.c_str()) % 100 != 0) || std::atoi(year.c_str()) % 400 == 0)
		return (true);
	return (false);
}

bool	BitcoinExchange::checkDay(const std::string& date, const std::string& month, const std::string& year)
{
	if (this->isLeapYear(year))
	{
		if (month == "02" && (date < "01" || date > "29"))
			return (false);
		else if (month != "   ")
	}
	else
	{
		if (month == "02" && (date < "01" || date > "28"))
			return (false);
	}
}

