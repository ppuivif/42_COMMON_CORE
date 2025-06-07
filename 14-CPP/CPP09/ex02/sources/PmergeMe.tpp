#include "PmergeMe.hpp"

template<template<typename, typename> class T>
PmergeMe<T>::PmergeMe(){}

template<template<typename, typename> class T>
PmergeMe<T>::~PmergeMe(){
	typename T<data *, std::allocator<data *> >::iterator it = this->_dataContainer.begin();
	for(; it != this->_dataContainer.end(); it++){
		delete *it;
	}
	delete [] this->_array;
}

template<template<typename, typename> class T>
PmergeMe<T>::PmergeMe(PmergeMe const & rhs){
	*this = rhs;
}

template<template<typename, typename> class T>
PmergeMe<T> PmergeMe<T>::operator=(PmergeMe<T> const & rhs){
	if (this != &rhs){
		typename T<data *, std::allocator<data *> >::iterator it1 = this->_dataContainer.begin();
		for(; it1 != this->_dataContainer.end(); it1++){
			delete *it1;
			this->_dataContainer.erase(it);
		}
		typename T<data *, std::allocator<data *> >::iterator it2 = rhs->_dataContainer.begin();
		for(; it2 != rhs->_dataContainer.end(); it2++){
			std::pair<int, int> pair;
			pair = std::make_pair(rhs->_dataContainer->valuespair.first, rhs->_dataContainer->valuespair.second);
			data * numberStruct = new data;
			numberStruct->valuesPair = pair;
			numberStruct->associated = rhs->_dataContainer->associated;
			this->_dataContainer.insert(this->_dataContainer.end(), numberStruct);
		}

		typename T<int, std::allocator<int> >::iterator it3 = this->_intContainer.begin();
		for(; it3 != this->_intContainer.end(); it3++){
			this->_intContainer.erase(it3);
		}
		typename T<int, std::allocator<int> >::iterator it4 = rhs->_intContainer.begin();
		for(; it4 != rhs->_dataContainer.end(); it4++){
			this->_intContainer.insert(this->_intContainer.end(), *rhs->_intContainer);
		}

		typename T<int, std::allocator<int> >::iterator it5 = this->_indexContainerFromJacobsthal.begin();
		for(; it5 != this->_indexContainerFromJacobsthal.end(); it5++){
			this->_indexContainerFromJacobsthal.erase(it5);
		}
		typename T<int, std::allocator<int> >::iterator it6 = rhs->_indexContainerFromJacobsthal.begin();
		for(; it6 != rhs->_indexContainerFromJacobsthal.end(); it6++){
			this->_indexContainerFromJacobsthal.insert(this->_indexContainerFromJacobsthal.end(), *rhs->_indexContainerFromJacobsthal);
		}
	}
	return(*this);
}

template<template<typename, typename> class T>
int PmergeMe<T>::checkArguments(int argc, char **argv){

	int i = 1;
	char *endptr = NULL;
	this->_array = new int[argc + 1];

	this->_array[0] = 0;
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
		this->_array[i] = number;
		i++;
	}
	this->_array[i] = -1;
	return (0);
}

template<template<typename, typename> class T>
int PmergeMe<T>::parsingArguments(int argc, char **argv){
	
	if (argc < 2){
		std::cerr << BOLD_RED << "Error : wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	
	if (this->checkArguments(argc, argv) == 1)
		return (1);
	return (0);
}

template<template<typename, typename> class T>
bool	PmergeMe<T>::checkIfDataSorted(int argc){
	int i = 1;
	
	while (this->_array[i] != -1){
		if (i + 1 <= argc){
			if (this->_array[i] > this->_array[i + 1])
				return (false);
		}
		i++;
	}
	std::cout << BOLD_RED << "arguments are already sorted" << NORMAL << std::endl; 
	return (true);
}

static void initDataStruct(data * numberStruct, std::pair<int, int> pair){
	numberStruct->associated = NULL;
	numberStruct->valuesPair = pair;
}

template<template<typename, typename> class T>
void PmergeMe<T>::displayDataContainerContent(){
	typename T<data *, std::allocator<data *> >::iterator it = this->_dataContainer.begin();
	for(; it != this->_dataContainer.end(); it++){
		std::cout << (*it)->valuesPair.first << " | ";
		std::cout << (*it)->valuesPair.second << " | ";
		if ((*it)->associated)
			std::cout << (*it)->associated->valuesPair.first;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<template<typename, typename> class T>
void PmergeMe<T>::displayIntContainerContent(){
	typename T<int, std::allocator<int> >::iterator it = this->_intContainer.begin();
	for(; it != this->_intContainer.end(); it++)
		std::cout << *it << std::endl;
}

template<template<typename, typename> class T>
void PmergeMe<T>::fillContainers(int argc){

	int firstElement;
	int secondElement;

	for (int i = 1; i < argc; i++){
		std::pair<int, int> pair;
		firstElement = this->_array[i];
		if (i + 1 < argc){
			i++;
			secondElement = this->_array[i];
		}
		else
			secondElement = -1;
		if (firstElement > secondElement)
			pair = std::make_pair(firstElement, secondElement);
		else
			pair = std::make_pair(secondElement, firstElement);

		data * numberStruct = new data;
		initDataStruct(numberStruct, pair);
		this->_dataContainer.insert(this->_dataContainer.end(), numberStruct);
	}
}

/*template<typename T> 
typename T<data *>::iterator PmergeMe<T>::findAssociatedIteratorForData(T<data *>::iterator pairToInsertIt){

	std::vector<data *>::iterator result = std::find(_dataContainer.begin(), _dataContainer.end(), (*pairToInsertIt)->associated);
	return (result);
}*/

/*template<typename T> 
typename T<int>::iterator PmergeMe<T>::findAssociatedIteratorForInt(T<data *>::iterator valueToInsertIt){

	std::vector<int>::iterator result = std::find(_intVector.begin(), _intVector.end(), (*valueToInsertIt)->valuesPair.first);

	return (result);
}*/

template<template<typename, typename> class T>
typename T<data *, std::allocator<data *> >::iterator PmergeMe<T>::binarySearchForData(data *dataToInsert, typename T<data *, std::allocator<data *> >::iterator lowerLimit, typename T<data *, std::allocator<data *> >::iterator upperLimit){

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
//	std::cout << "element to reintegrate : " << valueToInsert << " at upperLimit : " << (*upperLimit)->valuesPair.first << std::endl;
	return (upperLimit);
}

template<template<typename, typename> class T>
void PmergeMe<T>::movePairWithLargestValue(size_t i, size_t limit, bool isOdd){

	typename T<data *, std::allocator<data *> >::iterator it;
	typename T<data *, std::allocator<data *> >::iterator firstPairIt;
	typename T<data *, std::allocator<data *> >::iterator secondPairIt;
	
	int firstPairMaxValue;
	int secondPairMaxValue;

	it = this->_dataContainer.begin() + i;
	firstPairIt = it;
	firstPairMaxValue = (*it)->valuesPair.first;

	if (i < limit){
		it++;
		secondPairIt = it;
		secondPairMaxValue = (*it)->valuesPair.first;
		if (secondPairMaxValue > firstPairMaxValue){
			(*firstPairIt)->associated = *secondPairIt;
			this->_dataContainer.insert(this->_dataContainer.end(), *secondPairIt);
			this->_dataContainer.erase(this->_dataContainer.begin() + i + 1);
		}
		else{
			(*secondPairIt)->associated = *firstPairIt;
			this->_dataContainer.insert(this->_dataContainer.end(), *firstPairIt);
			this->_dataContainer.erase(this->_dataContainer.begin() + i);
		}
	}
	if (i == limit && isOdd == true){ //for last pair when odd number of pairs
			this->_dataContainer.insert(this->_dataContainer.end(), *firstPairIt);
			this->_dataContainer.erase(this->_dataContainer.begin() + i);
	}
}

template<template<typename, typename> class T>
int PmergeMe<T>::reintegratePairWithSmallestValue(int i){

		typename T<data *, std::allocator<data *> >::iterator pairToInsertIt = this->_dataContainer.begin() + i;
		typename T<data *, std::allocator<data *> >::iterator upperLimit;
		typename T<data *, std::allocator<data *> >::iterator lowerLimit;
		typename T<data *, std::allocator<data *> >::iterator insertLocation;
//			std::cout << "toinsert : " << (*(pairToInsertIt))->valuesPair.first << std::endl;
//			std::cout << "associated : " << (*pairToInsertIt)->associated->valuesPair.first << std::endl;

//			upperLimit = std::lower_bound(pairToInsertIt, this->_dataContainer.end(), (*pairToInsertIt)->associated);

//		lowerLimit = pairToInsertIt;
		lowerLimit = this->_dataContainer.begin();

//		upperLimit = findAssociatedIteratorForData(pairToInsertIt);
		upperLimit = std::find(this->_dataContainer.begin(), this->_dataContainer.end(), (*pairToInsertIt)->associated);

		insertLocation = binarySearchForData(*pairToInsertIt, lowerLimit, upperLimit);

//		std::cout << "pair to insert : " << (*pairToInsertIt)->valuesPair.first << " | " << (*pairToInsertIt)->valuesPair.second << std::endl;
//		std::cout << "insertlocation : " << (*insertLocation)->valuesPair.first << std::endl;

		if (insertLocation > pairToInsertIt + 1){
			this->_dataContainer.insert(insertLocation, *pairToInsertIt);
			this->_dataContainer.erase(this->_dataContainer.begin() + i);
//			std::cout << "new vector content" << std::endl;
//			this->displayDataVectorContent();
			return (1);
		}
		if (insertLocation < pairToInsertIt){
			this->_dataContainer.insert(insertLocation, *pairToInsertIt);
			this->_dataContainer.erase(this->_dataContainer.begin() + i + 1);
//			std::cout << "new vector content" << std::endl;
//			this->displayDataVectorContent();
			return (-1);

			//				std::cout << "toerase : " << (*(this->_dataContainer.begin() + i))->valuesPair.first << std::endl;

		}
		return (1);
}

template<template<typename, typename> class T>
bool PmergeMe<T>::sortPairsOnMaxValue(int increment){

	int end = false;

//	std::cout << "increment : " << increment << std::endl;

	int divider = pow(2, increment);
	size_t remainingVectorSize = this->_dataContainer.size() / divider;
	if (this->_dataContainer.size() % divider != 0)
		remainingVectorSize = this->_dataContainer.size() / pow(2, increment) + 1;

//	std::cout << "remainingVectorSize : " << remainingVectorSize << std::endl;

	size_t start = this->_dataContainer.size() - remainingVectorSize;
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
	
//	size_t newStart = this->_dataContainer.size() - remainingVectorSize / 2 - 1;
	size_t newStart = this->_dataContainer.size() - remainingVectorSize / 2;
	if (this->_dataContainer.size() % divider != 0){
//		newStart = this->_dataContainer.size() - remainingVectorSize / 2 - 2;
		newStart = this->_dataContainer.size() - remainingVectorSize / 2 - 1;
	}
//	std::cout << "newstart : " << newStart << std::endl;
	
	size_t newLimit = start;
//	std::cout << "newLimit : " << newLimit << std::endl;

	if (remainingVectorSize > 2){
		for (int i = newStart; i >= (int)newLimit; i--) //i defined as an integer to verify when < 0 
			if (reintegratePairWithSmallestValue(i) < 0)
				i++;
	}
//	this->displayVectorContent();

	return (true);
}

template<template<typename, typename> class T>
typename T<int, std::allocator<int> >::iterator PmergeMe<T>::binarySearchForInt(int valueToInsert, typename T<int, std::allocator<int> >::iterator lowerLimit, typename T<int, std::allocator<int> >::iterator upperLimit){

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

template<template<typename, typename> class T>
void PmergeMe<T>::dislayIndexSequence(){

	size_t dataContainerSize = this->_dataContainer.size();
	std::cout << "dataContainerSize : " << dataContainerSize << std::endl;
	std::cout << "index sequence from Jacobsthal : ";
	for (typename T<int, std::allocator<int> >::iterator it = this->_indexContainerFromJacobsthal.begin(); it !=  this->_indexContainerFromJacobsthal.end(); it++)
		std::cout << *it << ", ";
	
	std::cout << std::endl;
}

template<template<typename, typename> class T>
void	PmergeMe<T>::createIndexSequenceWithJacobsthal(){
	
	typename T<int, std::allocator<int> > _indexContainer;
	size_t dataContainerSize = this->_dataContainer.size();
	unsigned int k = 1;
	unsigned int tk = 0;
	unsigned int previoustk = 1;
	unsigned int tmp = 1;

	while (tk < dataContainerSize){
		tk = (pow(2, k + 1) + pow(-1, k)) / 3;
		if (tk < dataContainerSize)
			this->_indexContainerFromJacobsthal.push_back(tk);
		tmp = tk;
		tk--;
		while (tk > previoustk){
			if (tk < dataContainerSize)
				this->_indexContainerFromJacobsthal.push_back(tk);
			tk--;
		}
		k++;
		previoustk = tmp;
	}
//	dislayIndexSequence();
}

template<template<typename, typename> class T>
void	PmergeMe<T>::integrateMinValueswithJacobsthal(){

	typename T<data *, std::allocator<data *> >::iterator dataContainerIt = this->_dataContainer.begin();
	for (; dataContainerIt != this->_dataContainer.end(); dataContainerIt++)
		this->_intContainer.push_back((*dataContainerIt)->valuesPair.first); // push max value into intVector

	if ((*this->_dataContainer.begin())->valuesPair.second != -1)
		this->_intContainer.insert(this->_intContainer.begin(), (*this->_dataContainer.begin())->valuesPair.second); // to insert first min value

	size_t dataContainerSize = this->_dataContainer.size();

	
	createIndexSequenceWithJacobsthal();


	typename T<int, std::allocator<int> >::iterator upperLimit;
	typename T<int, std::allocator<int> >::iterator lowerLimit;
	typename T<int, std::allocator<int> >::iterator insertLocation;

	for (unsigned int i = 0; i != dataContainerSize - 1; i++){

		unsigned int index = this->_indexContainerFromJacobsthal[i];
		typename T<data *, std::allocator<data *> >::iterator valueToInsertIt = this->_dataContainer.begin() + index;

		if ((*valueToInsertIt)->valuesPair.second >= 0){
			lowerLimit = this->_intContainer.begin();
//			upperLimit = findAssociatedIteratorForInt(valueToInsertIt);
			upperLimit = std::find(_intContainer.begin(), _intContainer.end(), (*valueToInsertIt)->valuesPair.first);
			insertLocation = binarySearchForInt((*valueToInsertIt)->valuesPair.second, lowerLimit, upperLimit);
			this->_intContainer.insert(insertLocation, (*valueToInsertIt)->valuesPair.second);
		}
//		displayIntVectorContent();
	}
}	

template<template<typename, typename> class T>
void	PmergeMe<T>::isContainerSorted(){
	std::vector<int, std::allocator<int> >::iterator it = this->_intContainer.begin();
	std::vector<int, std::allocator<int> >::iterator tmp;
	int first;
	int second;

	for(; it != this->_intContainer.end(); it++){
		first = *it;
		tmp = it;
		tmp++;
		if (tmp != this->_intContainer.end()){
			second = *tmp;
			if (first > second){
				std::cout << BOLD_RED << first << " > " << second << " : arguments are not sorted" << NORMAL << std::endl; 
//				return (false);
			}
		}
	}
//	std::cout << GREEN << "arguments are sorted" << NORMAL << std::endl; 
//	return (true);
}

template<template<typename, typename> class T>
void	PmergeMe<T>::displayArrayContent(){

	int i = 1;

	while (this->_array[i] != -1){
		std::cout << this->_array[i] << std::endl;
		i++;
	}
}
