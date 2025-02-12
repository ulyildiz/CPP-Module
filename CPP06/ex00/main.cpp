#include "ScalerConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	{
		std::string str(argv[1]);

		ScalerConverter::convert(str);
	}

/* 	{
		long	*a = new long(42);
		// static_cast
		{

			std::cout << "static_cast<float>(c): " << static_cast<ScalerConverter*>(a) << std::endl;
		} 

		// implicit cast
		{
			std::cout << "implicit cast: " << (ScalerConverter*)a << std::endl;
		}

		// explicit cast
		{
			std::cout << "explicit cast: " << char(a) << std::endl;
		}
		delete a;
	} */
    return (0);
}