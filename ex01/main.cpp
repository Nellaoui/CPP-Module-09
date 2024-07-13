#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{

	if (ac != 2 || av[1][0] == '\0')
	{
		std::cout << "Error : Arguments" << std::endl;
		exit(1);
	}
		RPN rpn;
		rpn.start(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
