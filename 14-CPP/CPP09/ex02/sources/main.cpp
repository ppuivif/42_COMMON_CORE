#include "PmergeMe.hpp"

int	main(int argc, char ** argv){

	std::clock_t start = std::clock();
	PmergeMe<std::vector> pmergeMeVector;
	if (pmergeMeVector.parsingArguments(argc, argv) == 1)
		return (1);
		
	if (pmergeMeVector.checkIfDataSorted(argc) == false){

		pmergeMeVector.fillContainers(argc);

//		pmergeMeVector.displayDataVectorContent(); //to erase

		pmergeMeVector.sortPairsOnMaxValue(0);

//		pmergeMeVector.displayDataVectorContent(); //to erase
//		std::cout << std::endl;

		pmergeMeVector.integrateMinValueswithJacobsthal();

		pmergeMeVector.displayIntContainerContent();

		pmergeMeVector.isContainerSorted();
	}
	else
		pmergeMeVector.displayArrayContent();

	std::clock_t end = std::clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "Execution time with vector: " << duration * 1000000 << " useconds" << std::endl;
	std::cout << "Execution time with vector: " << duration * 1000 << " mseconds" << std::endl;
	

}