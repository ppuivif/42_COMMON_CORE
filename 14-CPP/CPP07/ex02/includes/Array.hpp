#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

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
class Array{

	public:
		Array();
		Array(unsigned int n);
//		Array(unsigned int n, int a, int b, int c);
		Array(Array const & Array);

		Array<T>	operator=(Array const & rhs);
		~Array();
		size_t	size() const;
		T	& operator[](unsigned int index);
		const T	& operator[](unsigned int index) const;
		
		class	indexError : public std::exception
		{
			virtual const char	* what() const throw();
		};
		
		private:
		T		* _array;
		size_t	_size;
		bool	_isInitialized;
	};

template<typename T>
std::ostream	& operator<<(std::ostream & o, const Array<T> & rhs);

#include "../sources/Array.tpp"

#endif