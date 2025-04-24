#include "Span.hpp"

Span::Span(){
	this->_N = 0;
}

Span::~Span(){
	
}

Span::Span(const Span & rhs){
	this->_container = rhs._container;
	this->_N = rhs._N;
}

Span & Span::operator=(const Span & rhs){
	if (this != &rhs){
		this->_container = rhs._container;
		this->_N = rhs._N;
	}
	return (*this);
}

Span::Span(unsigned int N){
	this->_N = N;
}

const std::vector<int> & Span::getContainer() const{
	return (this->_container);
}


void Span::addNumber(int number){
	if (this->_container.size() < this->_N)
		this->_container.push_back(number);
	else
		throw (Span::containerIsFull());
}

int		Span::shortestSpan(){
	int	result;

	std::vector<int>::iterator it = this->_container.begin();
	result = *it;
	for(; it != this->_container.end(); it++){
		if (*it < result)
			result = *it;
	}
	return (result);
}

int		Span::longestSpan(){
	int	result;

	std::vector<int>::iterator it = this->_container.begin();
	result = *it;
	for(; it != this->_container.end(); it++){
		if (*it > result)
			result = *it;
	}
	return (result);

}

const char*	Span::containerIsFull::what() const throw() {
	return ("The container is full");
}

const char*	Span::notEnoughNumber::what() const throw() {
	return ("The container does not contain enough number");
}