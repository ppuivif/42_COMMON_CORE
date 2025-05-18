#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>

class PmergeMe{

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & rhs);
		PmergeMe operator=(PmergeMe const & rhs);

		int parsingArguments(int argc, char **argv);
		int checkArguments(char **argv);

	private:

};

#endif