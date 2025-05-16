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

void Span::addNumber(int number){
	if (this->_container.size() < this->_N)
		this->_container.push_back(number);
	else
		throw (Span::containerIsFull());
}

int	Span::shortestSpan(){
	if (this->_container.size() > 1){
		std::vector<int>tmp = this->_container;
		std::sort(tmp.begin(), tmp.end());
	
		int result = tmp.back() - tmp.front();
		int previewValue = tmp.front();
		int diff = 0;
		std::vector<int>::iterator it = tmp.begin();
		it++;
		
		for (; it != tmp.end(); it++){
			diff = *it - previewValue;
			if (diff < result)
				result = diff;
			previewValue = *it;
		}
		return (result);
	}
	throw (Span::notEnoughNumber());
}

int	Span::longestSpan(){
	int	result;

	if (this->_container.size() > 1){
		std::vector<int>tmp = this->_container;
		std::sort(tmp.begin(), tmp.end());
		result = tmp.back() - tmp.front();
		return (result);
	}
	throw (Span::notEnoughNumber());
}

void	Span::addNumber(Span source, unsigned int start, unsigned int size){
	unsigned int availableSize = this->_N - this->_container.size();
	
	if (availableSize == 0 || start > source._container.size()){
		std::cout << BOLD_RED << "any number could be added with range of iterators" << NORMAL << std::endl;
		return ;
	}
	if (start + size > source._container.size())
		size = source._container.size() - start;

	if (size > availableSize)
		size = availableSize;	

	std::vector<int>::iterator begin = source._container.begin() + start;
	std::vector<int>::iterator end = source._container.begin() + start + size;

	this->_container.insert(this->_container.end(), begin, end);
	std::cout << GREEN << size << " number(s) could be added with range of iterators" << NORMAL << std::endl;
}

void	Span::fillWithRandomValues(){
	std::srand((unsigned) std::time(NULL));
	int array[this->_N];

	for (unsigned int i = 0; i < this->_N; i++){
		array[i] = std::rand();
	}
	
	this->_container.insert(this->_container.end(), array, &array[this->_N]);
}

void	Span::displayContainerContent(){
	std::vector<int>::iterator it = this->_container.begin();
	int i = 0;
	for (; it != this->_container.end(); it++){
		std::cout << "value at index " << i << " is : "<< this->_container[i] << std::endl;
		i++;
	}
}

const char*	Span::containerIsFull::what() const throw() {
	return ("The container is full");
}

const char*	Span::notEnoughNumber::what() const throw() {
	return ("The container does not contain enough numbers to find shortest and longest spans");
}
