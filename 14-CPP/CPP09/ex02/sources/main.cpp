#include "PmergeMe.hpp"

int	main(int argc, char ** argv){

	PmergeMe pmergeMe;
	pmergeMe.parsingArguments(argc, argv);
	pmergeMe.fillContainers(argc, argv);
//	pmergeMe.displayVectorContent();
	pmergeMe.sortInsidePair();
	pmergeMe.displayVectorContent();
	pmergeMe.sortPairs();
	pmergeMe.displayVectorContent();

//	faire un isorted
// voir si limite de nombres d'entiers

}