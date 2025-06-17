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
#include <utility> //for pair
#include <cmath> //for pow
#include <algorithm> //for lower_bound, is_sorted
#include <ctime> //for clock

struct data
{
	std::pair<int, int> valuesPair;
	data * associated;
};

template<template<typename, typename> class T>
class PmergeMe{

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const & rhs);
		PmergeMe operator=(PmergeMe const & rhs);

		size_t	getNmemb() const;
		void	setArrayPtr(int **intArrayPtr);
		
		void	FordJohnsonSort(int argc);
		void	fillContainers(int argc);
		bool	sortPairsOnMaxValue(int increment);
		void	movePairWithLargestValue(size_t i, size_t limit, bool isOdd);
		int		reintegratePairWithSmallestValue(int i);
		typename T<data *, std::allocator<data *> >::iterator binarySearchForData(data *dataToInsert, typename T<data *, std::allocator<data *> >::iterator lowerLimit, typename T<data *, std::allocator<data *> >::iterator upperLimit);
		
		void	integrateMinValueswithJacobsthal();
		void	createIndexSequenceWithJacobsthal();
		typename T<int, std::allocator<int> >::iterator binarySearchForInt(int valueToInsert, typename T<int, std::allocator<int> >::iterator lowerLimit, typename T<int, std::allocator<int> >::iterator upperLimit);
		void	displayIndexSequence();
		
		void	transferSortedDataToArray();
		void	isContainerSorted();

		void	displayDataContainerContent();
		void	displayIntContainerContent();
		
	private:
		
		int *_arrayPtr;
		size_t _nmemb;
		
		T<data *, std::allocator<data *> > _dataContainer;
		T<int, std::allocator<int> > _intContainer;
		T<int, std::allocator<int> > _indexContainerFromJacobsthal;
		
};
	
int		parsingArguments(int argc, char **argv, int **intArrayPtr);
bool	checkIfDataSorted(int *intArray, int nmemb);
void	displayArrayContent(int *intArray, std::string message);
	
#include "../sources/PmergeMe.tpp"

#endif