#include "PmergeMe.hpp"

int	main(int argc, char ** argv){

	std::clock_t start = std::clock();
	PmergeMe pmergeMe;
	if (pmergeMe.parsingArguments(argc, argv) == 1)
		return (1);
	pmergeMe.fillContainers(argc, argv);

//	pmergeMe.displayDataVectorContent(); //to erase

	pmergeMe.sortPairsOnMaxValue(0);

//	pmergeMe.displayDataVectorContent(); //to erase

	pmergeMe.integrateMinValueswithJacobsthal();

	pmergeMe.displayIntVectorContent();

	std::clock_t end = std::clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "Execution time: " << duration * 1000000 << " useconds" << std::endl;
	std::cout << "Execution time: " << duration * 1000 << " mseconds" << std::endl;
	
//	faire un isorted
// voir si limite de nombres d'entiers

}