#include "MyFile.hpp"

MyFile::MyFile(std::string fileName, bool in_out)
{
	if (in_out)
		this->_fileName = fileName;
	else
		this->_fileName = fileName + ".replace";
	this->_in_out = in_out;
}

MyFile::~MyFile()
{
	if (this->_in_out)
	{
		if (this->input.is_open())
			this->input.close();
	}
	else
	{
		if (this->output.is_open())
			this->output.close();
	}	
}

std::string	&MyFile::getFileName(void)
{
	return (this->_fileName);
}

bool	MyFile::MyFileOpen(void)
{
	if (this->_in_out)
	{
		this->input.open(this->_fileName);
		if (!this->input.is_open())
			return (false);
	}
	else
	{
		this->output.open(this->_fileName);
		if (!this->output.is_open())
			return (false);
	}
	return (true);
}
