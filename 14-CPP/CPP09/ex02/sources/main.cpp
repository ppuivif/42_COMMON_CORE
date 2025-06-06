#include "PmergeMe.hpp"

int	main(int argc, char ** argv){

	std::clock_t start = std::clock();
	PmergeMe pmergeMe;
	if (pmergeMe.parsingArguments(argc, argv) == 1)
		return (1);
		
	if (pmergeMe.checkIfDataSorted(argc) == false){

		pmergeMe.fillContainers(argc);

//		pmergeMe.displayDataVectorContent(); //to erase

		pmergeMe.sortPairsOnMaxValue(0);

//		pmergeMe.displayDataVectorContent(); //to erase
//		std::cout << std::endl;

		pmergeMe.integrateMinValueswithJacobsthal();

		pmergeMe.displayIntVectorContent();

		pmergeMe.isVectorSorted();
	}
	else
		pmergeMe.displayArrayContent();

	std::clock_t end = std::clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "Execution time with vector: " << duration * 1000000 << " useconds" << std::endl;
	std::cout << "Execution time with vector: " << duration * 1000 << " mseconds" << std::endl;
	
//	faire un isorted
// voir si limite de nombres d'entiers

}