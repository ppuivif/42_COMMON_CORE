#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime> // for date
#include <map>
#include <algorithm>
#include <iomanip> //for setprecision

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

		int				argumentsParsing(int argc, char **argv);
		int 			loadDataCSVContent(void);
		int 			loadInfileContent(std::string infile);
		void			parsingData(std::string const & line, std::string fileType);
		float 			findExchangeRate(time_t finalDate);
		void			closeStreams(void);
		
	private:
		std::map<time_t, float> _exchangeRateMap;
		std::ifstream	_dataCSVContent;
		std::ifstream	_infileContent;
		
	};
	
long int	parsingDate(std::string const & line);
float		parsingValue(std::string const & line, std::string fileType);
	
//void		printFileContent(std::ifstream & file);
//void 		printMapContent(std::map<std::time_t, float> map);

#endif