#include "BitcoinExchange.hpp"

int main(int  ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : Please enter the Data" << std::endl;
		return 0;
	}
	try
	{
		std::string file = av[1];
		BitcoinExchange be;
		be.start(file);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
