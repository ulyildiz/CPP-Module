#ifndef MYFILE_HPP
# define MYFILE_HPP

# include <iostream>
# include <fstream>

class MyFile {
	private:
		std::string		_fileName;
		bool			_in_out;

	public:
		MyFile(std::string fileName, bool in_out);
		~MyFile();

		std::ofstream	output;
		std::ifstream	input;
		
		bool		MyFileOpen(void);
		std::string	&getFileName(void);
		
};

#endif