#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T & valueList, int key){

	typename T::iterator it;

	it = std::find(valueList.begin(), valueList.end(), key);

	if (it == valueList.end())
		throw (noOccurenceFound());
	return (it);
}

const char* noOccurenceFound::what() const throw() {
	return ("no occurrence found");
}

