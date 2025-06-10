#include "PmergeMe.hpp"

int	main(int argc, char ** argv){
	
	int *intArrayPtr = NULL;
	if (parsingArguments(argc, argv, &intArrayPtr) == 1){
		return (1);
	}
		
	if (checkIfDataSorted(intArrayPtr, argc - 1) == true){
		delete [] intArrayPtr;
		return (0);
	}
		
	displayArrayContent(intArrayPtr, "Before");

	std::clock_t vectorStart = std::clock();
	PmergeMe<std::vector> pmergeMeVector;
	pmergeMeVector.setArrayPtr(&intArrayPtr);
	pmergeMeVector.FordJohnsonSort(argc);
//	pmergeMeVector.displayIntContainerContent();
//	pmergeMeVector.isContainerSorted();
	std::clock_t vectorEnd = std::clock();
	double vectorDuration = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC;


	std::clock_t dequeStart = std::clock();
	PmergeMe<std::deque> pmergeMeDeque;
	pmergeMeDeque.setArrayPtr(&intArrayPtr);
	pmergeMeDeque.FordJohnsonSort(argc);
//	pmergeMeDeque.displayIntContainerContent();
//	pmergeMeDeque.isContainerSorted();
	std::clock_t dequeEnd = std::clock();
	double dequeDuration = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC;

	pmergeMeDeque.transferSortedDataToArray();
	displayArrayContent(intArrayPtr, "After");
	std::cout << GREEN << "Time to process a range of " << pmergeMeVector.getNmemb() << " elements with std::vector : " << NORMAL << vectorDuration * 1000000 << " us" << std::endl;
	std::cout << GREEN << "Time to process a range of " << pmergeMeDeque.getNmemb() << " elements with std::deque : " << NORMAL << dequeDuration * 1000000 << " us" << std::endl;

	delete [] intArrayPtr;
}