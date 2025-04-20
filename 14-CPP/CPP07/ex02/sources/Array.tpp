#include "Array.hpp"

template<typename T>
Array<T>::Array(){
	this->_array = new T[0];
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n){
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = T();
}

/*template<typename T>
Array<T>::Array(unsigned int n, int a, int b, int c) : _size(n){
	this->_array = new T[n];
	this->_array[0] = a;
	this->_array[1] = b;
	this->_array[2] = c;
	for (unsigned int i = 3; i < n; i++)
		this->_array[i] = T();
}*/

template<typename T>
Array<T>::Array(Array const & rhs){

	this->_array = new T[rhs._size];
	this->_size = rhs._size;
	for (unsigned int i = 0; i < rhs._size ; i++)
		this->_array[i] = rhs._array[i];
}

template<typename T>
Array<T>	Array<T>::operator=(Array const & rhs){

	if (this != &rhs){
		delete [] this->_array;
		this->_size = rhs._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < rhs._size ; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(){
		delete [] this->_array;
}

template<typename T>
size_t	Array<T>::size() const{
	return (this->_size);
}

template<typename T>
T	& Array<T>::operator[](unsigned int index){

	if (index >= 0 && index < this->_size)
		return (this->_array[index]);
	else
		throw (Array::IndexError());
}

template<typename T>
const T	& Array<T>::operator[](unsigned int index) const{

	if (index >= 0 && index < this->_size)
		return (this->_array[index]);
	else
		throw (Array::IndexError());
}

template<typename T>
const char	* Array<T>::IndexError::what() const throw()
{
	return ("Index is out of the bounds");
}

template<typename T>
std::ostream	& operator<<(std::ostream & os, const Array<T> & rhs){

	unsigned int size = rhs.size();
	for (unsigned int index = 0; index < size; index++)
		os << "value at index " << index << " is : " << rhs[index] << std::endl;
	return (os);
}
