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
#include <algorithm> //for lower_bound, is_sorted
#include <ctime> //for clock

struct data
{
	std::pair<int, int> valuesPair;
	data * associated;
//	std::vector<data *>::iterator currentIt;
};


class PmergeMe{

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & rhs);
		PmergeMe operator=(PmergeMe const & rhs);

		int parsingArguments(int argc, char **argv);
		int checkArguments(int argc, char **argv);
		void	fillContainers(int argc);
		bool	checkIfDataSorted(int argc);
//		void 	sortInsidePair();
//		void 	sortPairs();
		bool	sortPairsOnMaxValue(int increment);
		void	movePairWithLargestValue(size_t i, size_t limit, bool isOdd);
		int		reintegratePairWithSmallestValue(int i);

		void	createIndexSequenceWithJacobsthal();
		void	integrateMinValueswithJacobsthal();


		std::vector<data *>::iterator findAssociatedIteratorForData(std::vector<data *>::iterator pairToInsertIt);
		std::vector<int>::iterator findAssociatedIteratorForInt(std::vector<data *>::iterator valueToInsertIt);
		std::vector<data *>::iterator binarySearchForData(data *dataToInsert, std::vector<data *>::iterator lowerLimit, std::vector<data *>::iterator upperLimit);
		std::vector<int>::iterator binarySearchForInt(int valueToInsert, std::vector<int>::iterator lowerLimit, std::vector<int>::iterator upperLimit);
		
		void	displayDataVectorContent();
		void	displayIntVectorContent();
		void	dislayIndexSequence();
		void	isVectorSorted();
		void	displayArrayContent();



	private:

		int *_array;

		std::vector<int> _indexVectorFromJacobsthal; 

		std::vector<data *> _dataVector; 
		std::vector<int> _intVector;

		std::deque<data> _dataDeque;
//		std::vector<std::pair<int, int> > _pairVector; 
//		std::deque<std::pair<int, int> > _pairDeque; 
};

#endif