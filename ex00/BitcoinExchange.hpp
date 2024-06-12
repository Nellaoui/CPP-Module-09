#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <sstream>
#include <map>
# include <stdexcept>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();
		void start( std::string &name );
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

	private:
		void	_openFile(const std::string fileName);
		void	_checkDate(const std::string &date);


};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );
std::vector<std::string> ftSplit(const std::string &str, char delimiter);
void printDatabase(const std::map<std::string, float>& database) ;
#endif /* ************************************************* BITCOINEXCHANGE_H */
