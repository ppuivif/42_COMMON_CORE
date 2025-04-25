#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & rhs);
		MutantStack & operator=(const MutantStack & rhs);

		iterator	begin();
		iterator	end();

};

#include "../sources/MutantStack.tpp"

#endif