#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	BitcoinExchange bt;
	if (bt.loadDataCSVContent() == 1)
		return (1);
	if (bt.parsing(argc, argv) == 1)
		return (1);
	if (bt.getInfileContent(argv[1]) == 1)
		return (1);
	
//	std::cout <<  << std::endl;

	return (0);
}