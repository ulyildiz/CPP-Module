#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "./btc [input file]" << std::endl;
		return (1);
	}

	BitcoinExchange	data;
	
	if (!data.openFile("data.csv"))
		return (1);
	data.extractData();

	if (!data.openFile(argv[1]))
		return (1);

	data.parseInput();

}
