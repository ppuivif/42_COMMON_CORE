#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>
#include <algorithm>

#ifndef GREEN
# define GREEN "\033[32m"
#endif
#ifndef BOLD_RED
# define BOLD_RED "\033[1;31m"
#endif
#ifndef BOLD
# define BOLD "\033[1m"
#endif
#ifndef NORMAL
# define NORMAL "\033[0m"
#endif

class BitcoinExchange{

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & rhs);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);	
		~BitcoinExchange();

		int	parsing(int argc, char **argv);
		int loadDataCSVContent(void);
		std::ifstream & getDataCSVContent(void);
		int getInfileContent(std::string infile);
		void closeStreams(void);
		
		
	private:
		std::map<std::string, float> _map;
		std::ifstream	_dataCSVContent;
		std::ifstream	_infileContent;
		
};

void printFileContent(std::ifstream & file);

//static void printFileContent(std::ifstream file);

#endif