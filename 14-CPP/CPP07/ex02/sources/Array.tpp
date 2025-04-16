#include "Array.hpp"

template<typename T>
Array<T>::Array(){
	this->_array = new T[0];
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n){
	this->_array = new T[n];
	this->_size = n;
}

template<typename T>
Array<T>::Array(Array const & rhs){

	Array(rhs->_size);
	for (size_t i = 0; i < rhs->_size ; i++)
		this->_array[i] = rhs->_array[i];
	this->_size = rhs->_size;
}

template<typename T>
Array<T>	Array<T>::operator=(Array const & rhs){

	if (rhs != this)
		this = Array(rhs);
	return (this);
}

template<typename T>
Array<T>::~Array(){
		delete [] this->_array;
}

template<typename T>
size_t	Array<T>::size() const{
	return (this->_size)
}

template<typename T>
T	& Array<T>::operator[](int index){

	if (index >= 0 && index < this->_size)
		return (this->_array[index]);
	else
		throw (Array::indexError)
}