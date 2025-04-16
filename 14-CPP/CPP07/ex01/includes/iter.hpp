#ifndef	ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>

void	displayContent(T const & content){
	std::cout << content << std::endl;
}

//template <typename T>

//void	iter(const T * array, size_t size, void (*function)(T const &)){

template <typename T>

void	iter(T * array, size_t size, void (*function)(T const &)){

	for (size_t index = 0; index < size; index++)
		function(array[index]);
}

#endif