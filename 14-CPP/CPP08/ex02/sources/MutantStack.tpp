#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & rhs) : std::stack<T>(rhs){}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & rhs){
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return (this->c.end());
}
