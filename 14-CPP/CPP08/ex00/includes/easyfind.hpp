#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

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

template<typename T>
typename T::iterator easyfind(T & valueList, int key);

class	noOccurenceFound : public std::exception{
	public:
		virtual const char	* what() const throw();
};

#include "../sources/easyfind.tpp"

#endif