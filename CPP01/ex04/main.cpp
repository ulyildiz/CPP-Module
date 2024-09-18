#include "MyFile.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);

	MyFile input(argv[1], true);
	MyFile output(argv[1], false);

	if (!input.MyFileOpen())
	{
		std::cout << input.getFileName() << " couldn't open." << std::endl;
		return (1);
	}
	if (!output.MyFileOpen())
	{
		std::cout << output.getFileName() << " couldn't open." << std::endl;
		return (1);
	}

	std::string				inputString;
	std::string				result;
	std::string				s1 = argv[2];
	std::string::size_type	pos = 0;
	std::string::size_type	found;

	while (std::getline(input.input, inputString))
	{
		found = inputString.find(s1);
		while (found != std::string::npos)
		{
			result = inputString.substr(pos, found - pos);
			result.append(argv[3]);
			pos = found + s1.length();
			found = inputString.find(s1, pos);
		}
		output.output << result << std::endl;
	}
//	input.input.eof();
	return (0);
}
