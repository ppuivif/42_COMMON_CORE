#include "easyfind.hpp"

int	main(){

int j = 10;

std::vector<int> list;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	try{
		int i = *easyfind(list, j);
		std::cout << GREEN << "value " << i << " was successfully found" << NORMAL << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	return (0);
}