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

void PmergeMe::displayDataVectorContent(){
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

void PmergeMe::displayIntVectorContent(){
	std::vector<int>::iterator it = this->_intVector.begin();
	for(; it != this->_intVector.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}

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

std::vector<data *>::iterator PmergeMe::findAssociatedIteratorForData(std::vector<data *>::iterator pairToInsertIt){

/*	std::vector<data *>::iterator it = pairToInsertIt;
	while (it != this->_dataVector.end()){
		if (*it == (*pairToInsertIt)->associated)
			break;
		it++;
	}
	return (it);
}*/

	std::vector<data *>::iterator result = std::find(_dataVector.begin(), _dataVector.end(), (*pairToInsertIt)->associated);

	return (result);
}


std::vector<int>::iterator PmergeMe::findAssociatedIteratorForInt(std::vector<data *>::iterator valueToInsertIt){

/*	std::vector<data *>::iterator it = pairToInsertIt;
	while (it != this->_dataVector.end()){
		if (*it == (*pairToInsertIt)->associated)
			break;
		it++;
	}
	return (it);
}*/
	std::vector<int>::iterator result = std::find(_intVector.begin(), _intVector.end(), (*valueToInsertIt)->valuesPair.first);

	return (result);
}

std::vector<data *>::iterator PmergeMe::binarySearchForData(data *dataToInsert, std::vector<data *>::iterator lowerLimit, std::vector<data *>::iterator upperLimit){

//	std::vector<data *>::iterator it = lowerLimit;
	size_t searchSize = upperLimit - lowerLimit;
//	std::cout << "lowerlimit : " << (*lowerLimit)->valuesPair.first << std::endl;
//	std::cout << "upperlimit : " << (*upperLimit)->valuesPair.first << std::endl;
//	std::cout << "searchSize : " << searchSize << std::endl;
	int valueToInsert = dataToInsert->valuesPair.first;
//	std::vector<data *>::iterator result;

	if (valueToInsert < (*lowerLimit)->valuesPair.first)
		return (lowerLimit);
	while (searchSize > 1){
		if (valueToInsert < (*(lowerLimit + searchSize / 2))->valuesPair.first)
			upperLimit -= searchSize / 2;
		else
			lowerLimit += searchSize / 2;
		searchSize = upperLimit - lowerLimit;
	}
	return (upperLimit);
}

void PmergeMe::movePairWithLargestValue(size_t i, size_t limit, bool isOdd){

	std::vector<data *>::iterator it;
	std::vector<data *>::iterator firstPairIt;
	std::vector<data *>::iterator secondPairIt;
	
	int firstPairMaxValue;
	int secondPairMaxValue;

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
	if (i == limit && isOdd == true){ //for last pair when odd number of pairs
			this->_dataVector.insert(this->_dataVector.end(), *firstPairIt);
			this->_dataVector.erase(this->_dataVector.begin() + i);
	}
}

void PmergeMe::reintegratePairWithSmallestValue(int i){

		std::vector<data *>::iterator pairToInsertIt = this->_dataVector.begin() + i;
		std::vector<data *>::iterator upperLimit;
		std::vector<data *>::iterator lowerLimit;
		std::vector<data *>::iterator insertLocation;
//			std::cout << "toinsert : " << (*(pairToInsertIt))->valuesPair.first << std::endl;
//			std::cout << "associated : " << (*pairToInsertIt)->associated->valuesPair.first << std::endl;

//			upperLimit = std::lower_bound(pairToInsertIt, this->_dataVector.end(), (*pairToInsertIt)->associated);

		lowerLimit = pairToInsertIt;
		upperLimit = findAssociatedIteratorForData(pairToInsertIt);

		insertLocation = binarySearchForData(*pairToInsertIt, lowerLimit, upperLimit);

//			std::cout << "insertlocation : " << (*insertLocation)->valuesPair.first << std::endl;

		if (insertLocation > pairToInsertIt + 1){
			this->_dataVector.insert(insertLocation, *pairToInsertIt);

//				std::cout << "toerase : " << (*(this->_dataVector.begin() + i))->valuesPair.first << std::endl;

			this->_dataVector.erase(this->_dataVector.begin() + i);
		}
}


bool PmergeMe::sortPairsOnMaxValue(int increment){

	int end = false;

//	std::cout << "increment : " << increment << std::endl;

	int divider = pow(2, increment);
	size_t remainingVectorSize = this->_dataVector.size() / divider;
	if (this->_dataVector.size() % divider != 0)
		remainingVectorSize = this->_dataVector.size() / pow(2, increment) + 1;

//	std::cout << "remainingVectorSize : " << remainingVectorSize << std::endl;

	size_t start = this->_dataVector.size() - remainingVectorSize;
	size_t limit = remainingVectorSize / 2 + start;

//	std::cout << "start : " << start << std::endl;
//	std::cout << "limit : " << limit << std::endl;

	bool isOdd = true;
	if (remainingVectorSize % 2 == 0)
		isOdd = false;

	while (remainingVectorSize > 1 && end == false){
		
		for (size_t i = start; i <= limit; i++)
			movePairWithLargestValue(i, limit, isOdd);
//		this->displayVectorContent();
		increment++;
		end = this->sortPairsOnMaxValue(increment);
	}
//	std::cout << "remainingVectorSize (backward) : " << remainingVectorSize << std::endl;
//	std::cout << "start : " << start << std::endl;
	
	size_t newStart = this->_dataVector.size() - remainingVectorSize / 2 - 1;
	if (this->_dataVector.size() % divider != 0)
		newStart = this->_dataVector.size() - remainingVectorSize / 2 - 2;
//	std::cout << "newstart : " << newStart << std::endl;
	
	size_t newLimit = start;
//	std::cout << "newLimit : " << newLimit << std::endl;

	if (remainingVectorSize > 2){
		for (int i = newStart; i >= (int)newLimit; i--) //i defined as an integer to verify when < 0 
			reintegratePairWithSmallestValue(i);
	}
//	this->displayVectorContent();

	return (true);
}

std::vector<int>::iterator PmergeMe::binarySearchForInt(int valueToInsert, std::vector<int>::iterator lowerLimit, std::vector<int>::iterator upperLimit){

//	std::vector<data *>::iterator it = lowerLimit;
	size_t searchSize = upperLimit - lowerLimit;
//	std::cout << "lowerlimit : " << (*lowerLimit)->valuesPair.first << std::endl;
//	std::cout << "upperlimit : " << (*upperLimit)->valuesPair.first << std::endl;
//	std::cout << "searchSize : " << searchSize << std::endl;
//	std::vector<data *>::iterator result;

	if (valueToInsert < *lowerLimit)
		return (lowerLimit);
	while (searchSize > 1){
		if (valueToInsert < (*(lowerLimit + searchSize / 2)))
			upperLimit -= searchSize / 2;
		else
			lowerLimit += searchSize / 2;
		searchSize = upperLimit - lowerLimit;
	}
	return (upperLimit);
}

// std::vector<int>::iterator PmergeMe::findAssociatedIteratorForInt(std::vector<int>::iterator valueToInsertIt){

// 	std::vector<int>::iterator it = valueToInsertIt;
// 	while (it != this->_intVector.end()){
// 		if (*it == *valueToInsertIt)
// 			break;
// 		it++;
// 	}
// 	return (it);
// }

void PmergeMe::dislayIndexSequence(){

	size_t dataVectorSize = this->_dataVector.size();
	std::cout << "dataVectorSize : " << dataVectorSize << std::endl;
	std::cout << "index sequence from Jacobsthal : ";
	for (std::vector<int>::iterator it = this->_indexVectorFromJacobsthal.begin(); it !=  this->_indexVectorFromJacobsthal.end(); it++)
		std::cout << *it << ", ";
	
	std::cout << std::endl;
}

void	PmergeMe::createIndexSequenceWithJacobsthal(){
	
	std::vector<int> _indexVector;
	size_t dataVectorSize = this->_dataVector.size();
	unsigned int k = 1;
	unsigned int tk = 0;
	unsigned int previoustk = 1;
	unsigned int tmp = 1;

	while (tk < dataVectorSize){
		tk = (pow(2, k + 1) + pow(-1, k)) / 3;
		if (tk < dataVectorSize)
			this->_indexVectorFromJacobsthal.push_back(tk);
		tmp = tk;
		tk--;
		while (tk > previoustk){
			if (tk < dataVectorSize)
				this->_indexVectorFromJacobsthal.push_back(tk);
			tk--;
		}
		k++;
		previoustk = tmp;
	}
//	dislayIndexSequence();
}

void	PmergeMe::integrateMinValueswithJacobsthal(){

	std::vector<data *>::iterator dataVectorIt = this->_dataVector.begin();
	for (; dataVectorIt != this->_dataVector.end(); dataVectorIt++)
		this->_intVector.push_back((*dataVectorIt)->valuesPair.first); // push max value into intVector

	this->_intVector.insert(this->_intVector.begin(), (*this->_dataVector.begin())->valuesPair.second); // to insert first min value

	size_t dataVectorSize = this->_dataVector.size();

	
	createIndexSequenceWithJacobsthal();


	std::vector<int>::iterator upperLimit;
	std::vector<int>::iterator lowerLimit;
	std::vector<int>::iterator insertLocation;

	for (unsigned int i = 0; i != dataVectorSize - 1; i++){

		unsigned int index = this->_indexVectorFromJacobsthal[i];
		std::vector<data *>::iterator valueToInsertIt = this->_dataVector.begin() + index;

		if ((*valueToInsertIt)->valuesPair.second >= 0){
			lowerLimit = this->_intVector.begin();
			upperLimit = findAssociatedIteratorForInt(valueToInsertIt);
			insertLocation = binarySearchForInt((*valueToInsertIt)->valuesPair.second, lowerLimit, upperLimit);
			this->_intVector.insert(insertLocation, (*valueToInsertIt)->valuesPair.second);
		}
//		displayIntVectorContent();
	}
}	
