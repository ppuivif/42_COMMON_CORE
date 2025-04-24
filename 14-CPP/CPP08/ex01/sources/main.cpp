#include "Span.hpp"

int	main(){

	int N;
	std::cout << GREEN << "***************** test with N = 0 *****************" << NORMAL << std::endl;
	N = 0;
	Span span0(N);
	try{
		span0.displayContainerContent();
		span0.addNumber(1);
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	
	try{
		int shortestSpan = span0.shortestSpan();
		int longestSpan = span0.longestSpan();
		std::cout << "Shortest span is : " << shortestSpan << std::endl;
		std::cout << "Longest span is : " << longestSpan << std::endl;
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}

	std::cout << GREEN << "***************** test with N = 1 *****************" << NORMAL << std::endl;
	N = 1;
	Span span1(N);
	try{
		span1.addNumber(1);
		span1.displayContainerContent();
		span1.addNumber(2);
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}

	try{
		int shortestSpan = span1.shortestSpan();
		int longestSpan = span1.longestSpan();
		std::cout << "Shortest span is : " << shortestSpan << std::endl;
		std::cout << "Longest span is : " << longestSpan << std::endl;
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}

	std::cout << GREEN << "***************** test with N = 5 *****************" << NORMAL << std::endl;
	N = 5;
	Span span5(N);
	try{
		span5.addNumber(6);
		span5.addNumber(3);
		span5.addNumber(17);
		span5.addNumber(9);
		span5.addNumber(11);
		span5.displayContainerContent();
		span5.addNumber(6);
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	
	try{
		int shortestSpan = span5.shortestSpan();
		int longestSpan = span5.longestSpan();
		std::cout << "Shortest span is : " << shortestSpan << std::endl;
		std::cout << "Longest span is : " << longestSpan << std::endl;
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}

	std::cout << GREEN << "***************** test with using range of iterators and random values *****************" << NORMAL << std::endl;
	Span spanRandom(100);
	spanRandom.fillWithRandomValues();

	N = 2;
	Span spanItered(N);
	try{
		spanItered.addNumber(6);
		spanItered.addNumber(3);
		spanItered.addNumber(17);
		spanItered.addNumber(9);
		spanItered.addNumber(11);
		spanItered.addNumber(spanRandom, 50, 10);
		spanItered.displayContainerContent();
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}

	try{
		int shortestSpan = spanItered.shortestSpan();
		int longestSpan = spanItered.longestSpan();
		std::cout << "Shortest span is : " << shortestSpan << std::endl;
		std::cout << "Longest span is : " << longestSpan << std::endl;
	}
	catch(const std::exception &e){
		std::cout << BOLD_RED << e.what() << NORMAL << std::endl;
	}

}