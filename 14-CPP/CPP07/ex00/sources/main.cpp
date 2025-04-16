#include "whatever.hpp"

int	main(){
	int	a = 1;
	int	b = 2;

	std::string str1 = "Hello";
	std::string str2 = "world";
	
	std::cout << "Before swap, a = " << a << " and b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap, a = " << a << " and b = " << b << std::endl;

	std::cout << "Before swap, str1 = " << str1 << " and str2 = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap, str1 = " << str1 << " and str2 = " << str2 << std::endl << std::endl;
	
	std::cout << "Between a and b, max is : " << ::max(a, b) << std::endl;
	std::cout << "Between a and b, min is : " << ::min(a, b) << std::endl;
	std::cout << "Between str1 and str2, max is : " << ::max(str1, str2) << std::endl;
	std::cout << "Between str1 and str2, min is : " << ::min(str1, str2) << std::endl;
		
	return (0);
}

