#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	BitcoinExchange bt;
	if (bt.argumentsParsing(argc, argv) == 1)
		return (1);
	if (bt.loadDataCSVContent() == 1)
		return (1);
	if (bt.loadInfileContent(argv[1]) == 1)
		return (1);
	return (0);
}