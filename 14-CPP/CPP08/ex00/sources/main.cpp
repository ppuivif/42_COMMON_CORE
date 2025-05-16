#include "easyfind.hpp"

int	main(){

int j = 10;

std::vector<int> list1;

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);

	try{
		int i = *easyfind(list1, j);
		std::cout << GREEN << "value " << i << " was successfully found in list 1" << NORMAL << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}

std::deque<int> list2;

	list2.push_back(10);
	list2.push_back(20);
	list2.push_back(30);
	list2.push_back(40);

	try{
		int i = *easyfind(list2, j);
		std::cout << GREEN << "value " << i << " was successfully found in list 2" << NORMAL << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	return (0);
}