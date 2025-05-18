#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const & rhs){
	*this = rhs;
}

PmergeMe PmergeMe::operator=(PmergeMe const & rhs){
//	if (this != &rhs)
	(void)rhs;
	return(*this);
}

int PmergeMe::checkArguments(char **argv){

	int i = 1;
	char *endptr = NULL;

	while (argv[i]){
		long int number = strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || (strcmp(argv[i], "0") && number == 0)){
			std::cout << BOLD_RED << "Error : at least one argument is invalid" << NORMAL << std::endl;
			return (1);
		}
		if (number < 0 || number > INT_MAX){
			std::cout << BOLD_RED << "Error : at least one argument is out of range" << NORMAL << std::endl;
			return (1);
		}
//		std::cout << number << std::endl;
		i++;	
	}
	return (0);
}

int PmergeMe::parsingArguments(int argc, char **argv){

	if (argc < 2){
		std::cerr << BOLD_RED << "Error : wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	
	if (this->checkArguments(argv) == 1)
		return (1);

	return (0);
}

