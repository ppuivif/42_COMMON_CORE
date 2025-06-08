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
		
		void	createIndexSequenceWithJacobsthal();
		void	integrateMinValueswithJacobsthal();
		
		
		//		std::vector<data *>::iterator findAssociatedIteratorForData(std::vector<data *>::iterator pairToInsertIt);
		//		typename T<data *>::iterator findAssociatedIteratorForData(T<data *>::iterator pairToInsertIt);
		//		std::vector<int>::iterator findAssociatedIteratorForInt(std::vector<data *>::iterator valueToInsertIt);
		//		typename T<int>::iterator findAssociatedIteratorForInt(T<data *>::iterator valueToInsertIt);
		//		std::vector<data *>::iterator binarySearchForData(data *dataToInsert, std::vector<data *>::iterator lowerLimit, std::vector<data *>::iterator upperLimit);
		typename T<data *, std::allocator<data *> >::iterator binarySearchForData(data *dataToInsert, typename T<data *, std::allocator<data *> >::iterator lowerLimit, typename T<data *, std::allocator<data *> >::iterator upperLimit);
		//		std::vector<int>::iterator binarySearchForInt(int valueToInsert, std::vector<int>::iterator lowerLimit, std::vector<int>::iterator upperLimit);
		typename T<int, std::allocator<int> >::iterator binarySearchForInt(int valueToInsert, typename T<int, std::allocator<int> >::iterator lowerLimit, typename T<int, std::allocator<int> >::iterator upperLimit);
		
		//		void	displayDataVectorContent();
		void	displayDataContainerContent();
		//		void	displayIntVectorContent();
		void	displayIntContainerContent();
		void	dislayIndexSequence();
		//		void	isVectorSorted();
		void	transferSortedDataToArray();
		void	isContainerSorted();
		
		
		
		private:
		
		int *_arrayPtr;
		size_t _nmemb;
		
		T<data *, std::allocator<data *> > _dataContainer;
		T<int, std::allocator<int> > _intContainer;
		T<int, std::allocator<int> > _indexContainerFromJacobsthal;
		
		/*		std::vector<data *> _dataVector; 
		std::vector<int> _intVector;
		std::vector<int> _indexVectorFromJacobsthal; 
		
		std::deque<data *> _dataDeque;
		std::deque<int> _intDeque;
		std::vector<int> _indexDequeFromJacobsthal;*/
		
	};
	
	int		parsingArguments(int argc, char **argv, int **intArrayPtr);
	bool	checkIfDataSorted(int **intArray, int nmemb);
	void	displayArrayContent(int **intArray, std::string message);
	
	#include "../sources/PmergeMe.tpp"

#endif