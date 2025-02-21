#include "BitcoinExchange.hpp"

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
	this->inputFile.open(fileName, std::ios::in);
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
	while (std::getline(this->inputFile, line))
	{
		std::string	date = line.substr(0, line.find('|'));
		double		value = std::strtod(line.substr(line.find('|') + 1).c_str(), NULL);
		if (this->_dataBase.find(date) == this->_dataBase.end())
			std::cout << date << " : " << "No data" << std::endl;
		else if (value == 0)
			std::cout << date << " : " << "No value" << std::endl;
		else
			std::cout << date << " : " << value * this->_dataBase[date] << std::endl;
	}

	inputFile.close();
	if (inputFile.rdstate() == std::ios::failbit)
	{
		std::cerr << "Error: could not close file." << std::endl;
		return ;
	}
}
