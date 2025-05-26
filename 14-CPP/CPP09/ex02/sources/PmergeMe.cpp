#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const & rhs){
	*this = rhs;
}

PmergeMe PmergeMe::operator=(PmergeMe const & rhs){
//	if (this != &rhs)
	(void)rhs;
	return(*this);
}

int PmergeMe::checkArguments(char **argv){

	int i = 1;
	char *endptr = NULL;

	while (argv[i]){
		long int number = strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || (strcmp(argv[i], "0") && number == 0)){
			std::cout << BOLD_RED << "Error : at least one argument is invalid" << NORMAL << std::endl;
			return (1);
		}
		if (number < 0 || number > INT_MAX){
			std::cout << BOLD_RED << "Error : at least one argument is out of range" << NORMAL << std::endl;
			return (1);
		}
//		std::cout << number << std::endl;
		i++;	
	}
	return (0);
}

int PmergeMe::parsingArguments(int argc, char **argv){

	if (argc < 2){
		std::cerr << BOLD_RED << "Error : wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	
	if (this->checkArguments(argv) == 1)
		return (1);
	return (0);
}

/*static void initDataStruct(data * numberStruct, char * argv){
	numberStruct->associated = NULL;
	numberStruct->value = strtol(argv, NULL, 10);
}*/

void PmergeMe::displayVectorContent(){
	std::vector<std::pair<int, int> >::iterator it = this->_pairVector.begin();
	for(; it != this->_pairVector.end(); it++){
		std::cout << it->first << " | ";
		std::cout << it->second << std::endl;
	}
	std::cout << std::endl;
}

/*void PmergeMe::displayVectorContent(){
	std::vector<data>::iterator it = this->_dataVector.begin();
	for(; it != this->_dataVector.end(); it++)
		std::cout << it->value << std::endl;
	std::cout << std::endl;
}*/

/*void PmergeMe::fillContainers(int argc, char **argv){

	for (int i = 1; i < argc; i++){
		data numberStruct;
		initDataStruct(&numberStruct, argv[i]);
		this->_dataVector.insert(this->_dataVector.end(), numberStruct);
	}
}*/

void PmergeMe::fillContainers(int argc, char **argv){

/*	bool isEven = false;
	if ((argc - 1) % 2 == 0)
		isEven = true;*/

	int firstElement;
	int secondElement;

	for (int i = 1; i < argc; i++){
		std::pair<int, int> pair;
		firstElement = strtol(argv[i], NULL, 10);
		if (i + 1 < argc){
			i++;
			secondElement = strtol(argv[i], NULL, 10);
		}
		else
			secondElement = -1;
		if (firstElement > secondElement)
			pair = std::make_pair(firstElement, secondElement);
		else
			pair = std::make_pair(secondElement, firstElement);
		this->_pairVector.insert(this->_pairVector.end(), pair);
	}
}

/*void PmergeMe::sortInsidePair(){

	std::vector<data>::iterator it = this->_dataVector.begin();
	for (; it != this->_dataVector.end(); it++){
		std::vector<data>::iterator firstIt = it;
		int firstValue = it->value;
		it++;
		if (it != this->_dataVector.end()){
			int secondValue = it->value;
			if (secondValue > firstValue)
				std::swap(*it, *firstIt);
//				créer une paire ??
		}
		return;
	}
}*/


/*void PmergeMe::sortPairs(){

	std::vector<data>::iterator it = this->_dataVector.begin();
	size_t vectorSize = _dataVector.size();
	for (size_t i = 0; i != vectorSize - 1; i++){
		std::vector<data>::iterator firstItLargest = it;
		//		std::cout << "here" << std::endl;
		int firstPairMaxValue = it->value;
		it++;
		i++;
		if (i < vectorSize && it != this->_dataVector.end()){
//			std::vector<data>::iterator firstItSmallest = it;
			it++;
			i++;
			if (i < vectorSize && it != this->_dataVector.end()){
				std::vector<data>::iterator secondItLargest = it;
				int secondPairMaxValue = it->value;
				std::vector<data>::iterator current = it++;
				i++;	
				if (secondPairMaxValue > firstPairMaxValue){
					this->_dataVector.insert(this->_dataVector.end(), *secondItLargest);
					this->_dataVector.erase(secondItLargest);
					if (i < vectorSize && current != this->_dataVector.end()){
						std::cout << "here" << std::endl;
						std::vector<data>::iterator secondItSmallest = current;
						this->_dataVector.insert(this->_dataVector.end(), *secondItSmallest);
						this->_dataVector.erase(secondItSmallest);
						it = current;
					}
				}
				else{
					this->_dataVector.insert(this->_dataVector.end(), *firstItLargest);
					this->_dataVector.erase(firstItLargest);
//					this->_dataVector.insert(this->_dataVector.end(), *firstIt++);
				}
			}
		}
		it++;
	}
}*/


void PmergeMe::sortPairsOnMaxValue(int increment){

	std::vector<std::pair<int, int> >::iterator it;
	std::vector<std::pair<int, int> >::iterator firstPairIt;
	std::vector<std::pair<int, int> >::iterator secondPairIt;

	std::cout << "increment : " << increment << std::endl;

	size_t remainingVectorSize = this->_pairVector.size() / pow(2, increment);

	while (remainingVectorSize > 1){
		size_t limit = remainingVectorSize / 2;
		size_t start = this->_pairVector.size() - remainingVectorSize;
		std::cout << "start : " << start << std::endl;
		

		bool isOdd = true;
		if (remainingVectorSize % 2 == 0)
			isOdd = false;

		int firstPairMaxValue;
		int secondPairMaxValue;
		
		for (size_t i = start; i <= limit; i++){
			it = this->_pairVector.begin() + i;
			firstPairIt = it;
			firstPairMaxValue = it->first;
			if (i < limit){
				it++;
				secondPairIt = it;
				secondPairMaxValue = it->first;
				if (secondPairMaxValue > firstPairMaxValue){
					this->_pairVector.insert(this->_pairVector.end(), *secondPairIt);
					this->_pairVector.erase(this->_pairVector.begin() + i + 1);
				}
				else{
					this->_pairVector.insert(this->_pairVector.end(), *firstPairIt);
					this->_pairVector.erase(this->_pairVector.begin() + i);
				}
			}
			if (i == limit && isOdd == true){
					this->_pairVector.insert(this->_pairVector.end(), *firstPairIt);
					this->_pairVector.erase(this->_pairVector.begin() + i);
			}
		}
		this->displayVectorContent();
		increment+=1;
		this->sortPairsOnMaxValue(increment);
	}
}