#include "Span.hpp"

int	main(){

	std::srand((unsigned) time(NULL));
	Span span1(5);

	int number = 6;

	try{
		for (int i = 0; i < number; i++){
			span1.addNumber(std::rand());
			std::cout << span1.getContainer()[i] << std::endl;
		}
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	
	try{
		std::cout << "Shortest value is : " << span1.shortestSpan() << std::endl;
		std::cout << "Longest value is : " << span1.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}


}