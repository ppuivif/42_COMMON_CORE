#include "Span.hpp"

Span::Span{
	this->_N = 0;
}

Span::~Span{
	
}

Span::Span(const Span & rhs){
	this->_container = rhs._container;
	this->_N = rhs._N;
}

Span & Span::operator=(const Span & rhs){
	if (this != rhs){
		this->_container = rhs._container;
		this->_N = rhs._N;
	}
	return (*this);
}

Span::Span(int N) : {
	this->_N = N;
}

Span::addNumber(int number){
	if (this->_container.size() < this->_N)
	this->_container.push_back(number);
	else
		throw (Span::containerIsFull());

}

int		shortestSpan(){
	int	result;

	std::vector<int>::iterator it = begin(this->_container);
	result = *it;
	for(; it != end(this->_container); it++){
		if (*it < result)
			result = *it;
	}
	return (result);
}

int		longestSpan(){
	int	result;

	std::vector<int>::iterator it = begin(this->_container);
	result = *it;
	for(; it != end(this->_container); it++){
		if (*it > result)
			result = *it;
	}
	return (result);

}