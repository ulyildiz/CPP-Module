#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>

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

	std::stringstream ss(line);
	std::string date, pipe, value;
	ss >> date >> pipe >> value;

	if (date != "date" || pipe != "|" || value != "value")
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
		try {
			std::string sdate = line.substr(0, line.find('|') - 1);
			std::string svalue = line.substr(line.find('|') + 1);
			float 		fvalue;

			this->checkDate(sdate);
			this->checkValue(svalue, &fvalue);

			float dValue = this->dataValue(sdate);

			std::cout << sdate << " => " << fvalue << " = " << fvalue * dValue << std::endl;
		} catch(const std::out_of_range& e) {
			std::cerr << "Error: bad input => " << line << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			errno = 0;
		}
	}
}

bool	BitcoinExchange::isLeapYear(const int& year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return (true);
	return (false);
}

bool	checkSyntax(const std::string& date)
{
	int	dashcount = 0;
	
	for (std::string::size_type i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			return (true);
		if (date[i] == '-')
		{
			if (i == 0 || i == date.size() - 1)
				return (false);
			dashcount++;
		}
	}
	if (dashcount != 2)
		return (true);
	return (false);
}

void	BitcoinExchange::checkDate(const std::string& date)
{
	if (checkSyntax(date))
		throw std::invalid_argument("Error: bad input => " + date);

	int	year, month, day;
	std::string	syear, smonth, sday;
	std::stringstream	ss(date);

	std::getline(ss, syear, '-');
	std::getline(ss, smonth, '-');
	std::getline(ss, sday);

	year = std::atoi(syear.c_str());
	month = std::atoi(smonth.c_str());
	day = std::atoi(sday.c_str());

	if (errno == ERANGE || year < 0 || month < 0 || day < 0)
		throw std::invalid_argument("Error: bad input => " + date);
	
	switch (month)
	{
		case 2:
			if (this->isLeapYear(year) ? (day < 1 || day > 29) : (day < 1 || day > 28))
				throw std::invalid_argument("Error: bad input => " + date);
			break;
		case 4: case 6: case 9: case 11:
			if (day < 1 || day > 30)
				throw std::invalid_argument("Error: bad input => " + date);
			break;
		default:
			if (day < 1 || day > 31)
				throw std::invalid_argument("Error: bad input => " + date);
			break;
	}
}

void	BitcoinExchange::checkValue(const std::string& value, float* fvalue)
{
	if (value.empty() || value == " ")
		throw std::invalid_argument("Error: empty value.");

	*fvalue = std::strtof(value.c_str(), NULL);
	
	if (errno == ERANGE || *fvalue > 999)
		throw std::invalid_argument("Error: too large number.");
	else if (*fvalue < 1)
		throw std::invalid_argument("Error: not a positive number.");
}

double	BitcoinExchange::dataValue(const std::string& date)
{
	std::map<std::string, double>::iterator it = this->_dataBase.lower_bound(date);

	if (it != _dataBase.end() && it == _dataBase.find(date))
		return (it->second);
	else if (it == _dataBase.begin())
	{
		if (date.compare(it->first) < 0)
			throw std::invalid_argument("Error: date is too early.");
	}
	else
		--it;
	return (it->second);
}
