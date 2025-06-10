#include "PmergeMe.hpp"

static int checkArguments(int argc, char **argv, int **intArrayPtr){

	int i = 1;
	char *endptr = NULL;
	int *intArray = new int[argc + 1];
	intArray[0] = 0;

	while (argv[i]){
		long int number = strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || (strcmp(argv[i], "0") && number == 0)){
			std::cout << BOLD_RED << "Error : at least one argument is invalid" << NORMAL << std::endl;
			delete [] intArray;
			return (1);
		}
		if (number < 0 || number > INT_MAX){
			std::cout << BOLD_RED << "Error : at least one argument is out of range" << NORMAL << std::endl;
			delete [] intArray;
			return (1);
		}
		intArray[i] = number;
		i++;
	}

	intArray[i] = -1;
	*intArrayPtr = intArray;
	return (0);
}

int parsingArguments(int argc, char **argv, int **intArrayPtr){
	
	if (argc < 2){
		std::cerr << BOLD_RED << "Error : wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	
	if (checkArguments(argc, argv, intArrayPtr) == 1)
		return (1);

	return (0);
}

bool	checkIfDataSorted(int *intArray, int nmemb){

	int i = 1;
	
	while (intArray[i] != -1){
		if (i + 1 <= nmemb){
			if (intArray[i] > intArray[i + 1])
			return (false);
		}
		i++;
	}
	std::cout << BOLD_RED << "arguments are already sorted" << NORMAL << std::endl; 
	return (true);
}

void	displayArrayContent(int *intArray, std::string message){
	
	int i = 1;
	
	std::cout << GREEN << message << ":	" << NORMAL;
	while (intArray[i] != -1){
		std::cout << intArray[i] << " ";
		i++;
	}
	std::cout << std::endl;
}
