#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class Span{
	public:
		Span();
		~Span();
		Span(const Span & rhs);
		Span & operator=(const Span & rhs);
		
		Span(unsigned int N);

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		
	private:
		unsigned int		N;
		std::vector<int>	_container;

		class	containerIsFull : public std::exception{
			public:
				virtual const char	* what() const throw();
		};
	
		class	notFound : public std::exception{
			public:
				virtual const char	* what() const throw();
		};

	};
	
#endif