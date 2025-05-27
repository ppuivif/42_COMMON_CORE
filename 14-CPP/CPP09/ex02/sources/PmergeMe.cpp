#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){
	std::vector<data *>::iterator it = this->_dataVector.begin();
	for(; it != this->_dataVector.end(); it++){
		delete *it;
	}
}

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

static void initDataStruct(data * numberStruct, std::pair<int, int> pair){
	numberStruct->associated = NULL;
	numberStruct->valuesPair = pair;
}

void PmergeMe::displayVectorContent(){
	std::vector<data *>::iterator it = this->_dataVector.begin();
	for(; it != this->_dataVector.end(); it++){
		std::cout << (*it)->valuesPair.first << " | ";
		std::cout << (*it)->valuesPair.second << " | ";
		if ((*it)->associated){
			std::cout << (*it)->associated->valuesPair.first;
//			std::cout << &(*(*it)->associated);
//			std::cout << (*(*it)->associated->currentIt)->valuesPair.first;
		}
		std::cout << std::endl;
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

		data * numberStruct = new data;
		initDataStruct(numberStruct, pair);
		this->_dataVector.insert(this->_dataVector.end(), numberStruct);
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

std::vector<data *>::iterator PmergeMe::findAssociatedIterator(std::vector<data *>::iterator pairToInsertIt){

	std::vector<data *>::iterator it = pairToInsertIt;
	while (it != this->_dataVector.end()){
		if (*it == (*pairToInsertIt)->associated)
			break;
		it++;
	}
	return (it);
}



std::vector<data *>::iterator PmergeMe::binarySearch(data *dataToInsert, std::vector<data *>::iterator lowerLimit, std::vector<data *>::iterator upperLimit){

//	std::vector<data *>::iterator it = lowerLimit;
	size_t searchSize = upperLimit - lowerLimit;
	std::cout << "lowerlimit : " << (*lowerLimit)->valuesPair.first << std::endl;
	std::cout << "upperlimit : " << (*upperLimit)->valuesPair.first << std::endl;
	std::cout << "searchSize : " << searchSize << std::endl;
	int valueToInsert = dataToInsert->valuesPair.first;
//	std::vector<data *>::iterator result;

	while (searchSize > 1){
		if (valueToInsert < (*(lowerLimit + searchSize / 2))->valuesPair.first)
			upperLimit -= searchSize / 2;
		else
			lowerLimit += searchSize / 2;
		searchSize = upperLimit - lowerLimit;
	}
	return (upperLimit);
}

bool PmergeMe::sortPairsOnMaxValue(int increment){

//	std::vector<std::pair<int, int> >::iterator it;
	std::vector<data *>::iterator it;
//	std::vector<std::pair<int, int> >::iterator firstPairIt;
	std::vector<data *>::iterator firstPairIt;
//	std::vector<std::pair<int, int> >::iterator secondPairIt;
	std::vector<data *>::iterator secondPairIt;
	int end = false;

	std::cout << "increment : " << increment << std::endl;

	int divider = pow(2, increment);
	size_t remainingVectorSize = this->_dataVector.size() / divider;
	if (this->_dataVector.size() % divider != 0)
		remainingVectorSize = this->_dataVector.size() / pow(2, increment) + 1;
	std::cout << "remainingVectorSize : " << remainingVectorSize << std::endl;

	size_t start = this->_dataVector.size() - remainingVectorSize;
	size_t limit = remainingVectorSize / 2 + start;
//	std::cout << "start : " << start << std::endl;
//	std::cout << "limit : " << limit << std::endl;

	bool isOdd = true;
	if (remainingVectorSize % 2 == 0)
		isOdd = false;

	while (remainingVectorSize > 1 && end == false){

		int firstPairMaxValue;
		int secondPairMaxValue;
		
		for (size_t i = start; i <= limit; i++){
			it = this->_dataVector.begin() + i;
			firstPairIt = it;
			firstPairMaxValue = (*it)->valuesPair.first;
			if (i < limit){
				it++;
				secondPairIt = it;
				secondPairMaxValue = (*it)->valuesPair.first;
				if (secondPairMaxValue > firstPairMaxValue){
					(*firstPairIt)->associated = *secondPairIt;
					this->_dataVector.insert(this->_dataVector.end(), *secondPairIt);
					this->_dataVector.erase(this->_dataVector.begin() + i + 1);
				}
				else{
					(*secondPairIt)->associated = *firstPairIt;
					this->_dataVector.insert(this->_dataVector.end(), *firstPairIt);
					this->_dataVector.erase(this->_dataVector.begin() + i);
				}
			}
			if (i == limit && isOdd == true){
					this->_dataVector.insert(this->_dataVector.end(), *firstPairIt);
					this->_dataVector.erase(this->_dataVector.begin() + i);
			}
		}
		this->displayVectorContent();
		increment++;
		end = this->sortPairsOnMaxValue(increment);
	}
	std::cout << "remainingVectorSize (backward) : " << remainingVectorSize << std::endl;
//	std::cout << "start : " << start << std::endl;
	
	size_t newStart = this->_dataVector.size() - remainingVectorSize / 2 - 1;
	if (this->_dataVector.size() % divider != 0)
	newStart = this->_dataVector.size() - remainingVectorSize / 2 - 2;
	std::cout << "newstart : " << newStart << std::endl;
	
//	std::cout << "limit : " << start << std::endl;
	size_t newLimit = start;
	std::cout << "newLimit : " << newLimit << std::endl;
	if (remainingVectorSize > 2){
		for (size_t i = newStart; i >= newLimit; i--){
//		size_t i = newStart;
//		while (i >= newLimit && remainingVectorSize <= this->_dataVector.size()){
			std::vector<data *>::iterator pairToInsertIt = this->_dataVector.begin() + i;
			//std::vector<data *>::iterator pairToInsertIt = it;
			std::vector<data *>::iterator upperLimit;
			std::vector<data *>::iterator insertLocation;
			std::cout << "toinsert : " << (*(pairToInsertIt))->valuesPair.first << std::endl;
			std::cout << "associated : " << (*pairToInsertIt)->associated->valuesPair.first << std::endl;

//			upperLimit = std::lower_bound(pairToInsertIt, this->_dataVector.end(), (*pairToInsertIt)->associated);

			upperLimit = findAssociatedIterator(pairToInsertIt);

			insertLocation = binarySearch(*pairToInsertIt, pairToInsertIt, upperLimit);

			std::cout << "insertlocation : " << (*insertLocation)->valuesPair.first << std::endl;

			if (insertLocation > pairToInsertIt + 1){
				this->_dataVector.insert(insertLocation, *pairToInsertIt);

				std::cout << "toerase : " << (*(this->_dataVector.begin() + i))->valuesPair.first << std::endl;

				this->_dataVector.erase(this->_dataVector.begin() + i);
			}
			this->displayVectorContent();
//			i--;
		}
	}

	return (true);
}