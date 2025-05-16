#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For time()
#include <algorithm> //for begin and end

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

class Span{

	public:
		Span();
		~Span();
		Span(const Span & rhs);
		Span & operator=(const Span & rhs);
		
		Span(unsigned int N);
		const std::vector<int> & getContainer() const;
		
		void	addNumber(int number);
		void	addNumber(Span source, unsigned int start, unsigned int size);
		void	fillWithRandomValues();
		int		shortestSpan();
		int		longestSpan();
		void	displayContainerContent();
		
		private:
			unsigned int		_N;
			std::vector<int>	_container;
		
		class	containerIsFull : public std::exception{
			public:
				virtual const char	* what() const throw();
		};
		
		class	notEnoughNumber : public std::exception{
			public:
				virtual const char	* what() const throw();
		};
		
	};
	
#endif