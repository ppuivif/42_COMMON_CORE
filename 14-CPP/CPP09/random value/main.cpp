#include <iostream>
#include <ctime>
#include <cstring> //for strcmp
#include <climits> //for INT_MAX

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

int checkInput(const char * input){

	char *endptr = NULL;

	long int number = strtol(input, &endptr, 10);
	if (*endptr != '\0' || (strcmp(input, "0") && number == 0)){
		std::cout << BOLD_RED << "Error : at least one argument is invalid" << NORMAL << std::endl;
		return (-1);
	}
	if (number < 0 || number > INT_MAX){
		std::cout << BOLD_RED << "Error : at least one argument is out of range" << NORMAL << std::endl;
		return (-1);
	}
//		std::cout << number << std::endl;

	return (number);
}

int getNumber(){

	std::string input;
	long int number = -1;

	while (input.empty()){
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input.empty())
			std::cout << BOLD_RED << "Enter a valid input (non empty) : " << NORMAL;
		else{
			number = checkInput(input.c_str());
			break;
		}
	}
	return (number);
}	

int main(){

	std::srand((unsigned) std::time(NULL));
	
	unsigned int i = 0;

	std::cout << BOLD << "Enter the beginning number of the range : " << NORMAL;
	long int begin = getNumber();

	std::cout << BOLD << "Enter the end number of the range : " << NORMAL;
	long int end = getNumber();

	std::cout << BOLD << "Enter the quantity : " << NORMAL;
	long int nmemb = getNumber();

	if (begin == -1 || end == -1 || nmemb == -1)
		return (1);

	while (i < nmemb){
		int number = std::rand();
		if (number >= begin && number <= end){
			std::cout << number << " ";
			i++;
		}
	}
	return (0);
}