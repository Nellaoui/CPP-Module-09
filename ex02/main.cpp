#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	try
	{
		if (ac == 1)
		{
			cout << "Error" << endl;
			exit(EXIT_FAILURE);
		}
		PmergeMe pmm;
		pmm.start(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}