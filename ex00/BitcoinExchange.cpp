#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & __unused src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & __unused rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & __unused i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::_openFile(const std::string fileName)
{
	std::map<std::string, float> dataBase;
	std::ifstream file(fileName);
	if(!file.is_open())
		throw std::ios_base::failure("Failed To open file :" + fileName);
	std::string line;
	while(std::getline(file, line))
	{
		std::vector<std::string> tokens = ftSplit(line, '|');
		std::string data = tokens[0];
		float price = std::stof(tokens[1]);
		dataBase[data] = price;
	}
	// std::vector<std::string> key;
	for(std::map<std::string, float>::iterator it = dataBase.begin(); it != dataBase.end(); ++it)
	{
		_checkDate(it->first);
	}
	// printDatabase(dataBase);
}
void BitcoinExchange::_checkDate(const std::string &date)
{
		if(date.size() != 11)
		{
			std::cout << "Error : Invalid date size" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (date[4] != '-' || date[7] != '-' )
		{
			std::cout << "Error : Invalid date" << std::endl;
			exit(EXIT_FAILURE);
		}
		for (size_t i = 0; i < date.size(); i++)
		{
			if (i == 4 || i == 7)
				continue;
			if (!std::isdigit(date[i]))
			{
				exit(EXIT_FAILURE);
				std::cout << "Error : Invalid date, is Not Digit" << std::endl;
			}
		}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<std::string> ftSplit(const std::string &str, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream ss(str);
	while(getline(ss, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

void BitcoinExchange::start(std::string &Name)
{
	this->_openFile(Name);

}


void printDatabase(const std::map<std::string, float>& database) {
    std::cout << "Database Contents:" << std::endl;
    std::map<std::string, float>::const_iterator it;
    for (it = database.begin(); it != database.end(); ++it) {
        std::cout << "Date: " << it->first << ", Price: " << it->second << std::endl;
    }
}
/* ************************************************************************** */
