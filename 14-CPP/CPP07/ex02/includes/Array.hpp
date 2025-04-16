#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>


template<typename T>

class Array{

	public:
		Array();
		Array(unsigned int n);
		Array(Array const & Array);
		Array<T>	operator=(Array const & rhs);
		~Array();
		size_t	size() const;
		T	& operator[](int index);

	private:
		T		* _array;
		size_t	_size;
};


#endif