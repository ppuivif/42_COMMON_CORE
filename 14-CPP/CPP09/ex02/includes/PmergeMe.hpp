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
#include <vector>
#include <deque>
#include <utility>
#include <cmath> //for pow

struct data
{
	int	value;
	data * associated;
	std::vector<data>::iterator position;
};


class PmergeMe{

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & rhs);
		PmergeMe operator=(PmergeMe const & rhs);

		int parsingArguments(int argc, char **argv);
		int checkArguments(char **argv);
		void	fillContainers(int argc, char **argv);
//		void 	sortInsidePair();
//		void 	sortPairs();
		void 	sortPairsOnMaxValue(int increment);
		
		void	displayVectorContent();

	private:

		std::vector<data> _dataVector; 
		std::deque<data> _dataDeque; 
		std::vector<std::pair<int, int> > _pairVector; 
		std::deque<std::pair<int, int> > _pairDeque; 
};

#endif