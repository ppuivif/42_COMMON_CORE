#include "Array.hpp"
#include "Animals.hpp"

int	main (){

	Array<std::string> stringArray0(0);

	Array<std::string> stringArray1(10);

	stringArray1[0] = "Salut";
	stringArray1[1] = " ";
	stringArray1[2] = "les";
	stringArray1[3] = " ";
	stringArray1[4] = "amis";
	stringArray1[5] = "";

	Array<Animals> classArray0(0);
	
	Array<Animals> classArray1(10);

	classArray1[0] = Animals("dog", "mammel");
	classArray1[1] = Animals("snake", "reptile");
	classArray1[2] = Animals("shark", "fish");
	classArray1[3] = Animals("duck", "bird");

	Array<int> intArray0(0);

	Array<int> intArray1(10);

	intArray1[0] = 10;
	intArray1[1] = 9;
	intArray1[2] = 8;
	intArray1[3] = 7;

	Array<int> intArray2(5);
	intArray2 = intArray1;

	Array<int> intArray3(intArray1);
	
	const Array<int> intArray5(10);
	//const Array<int> intArray5(10, 5, 4, 3);

	std::cout << "---------------- Display content of stringArray0(0) ----------------" << std::endl;	
	std::cout << stringArray0 << std::endl;

	std::cout << "---------------- Display content of stringArray1(10) ----------------" << std::endl;	
	std::cout << stringArray1 << std::endl;

	std::cout << "---------------- Display content of classArray0(0) ----------------" << std::endl;	
	std::cout << classArray0 << std::endl;

	std::cout << "---------------- Display content of classArray1(10) ----------------" << std::endl;	
	std::cout << classArray1 << std::endl;

	std::cout << "---------------- Display content of intArray0(0) ----------------" << std::endl;	
	std::cout << intArray0 << std::endl;

	std::cout << "---------------- Display content of intArray1(10) with 4 initialized values ----------------" << std::endl;	
	std::cout << intArray1 << std::endl;

	std::cout << "---------------- Display content of intArray2(5) = intArray1(10) ----------------" << std::endl;	
	std::cout << intArray2 << std::endl;

	intArray2[0] = 20;
	std::cout << "---------------- Display content of intArray2 after modification of intArray2[0] value ----------------" << std::endl;	
	std::cout << intArray2 << std::endl;

	std::cout << "---------------- Display content of intArray1 ----------------" << std::endl;	
	std::cout << intArray1 << std::endl;

	std::cout << "---------------- Display content of intArray3 build with intArray1(10) ----------------" << std::endl;	
	std::cout << intArray3 << std::endl;

	intArray3[0] = 20;
	std::cout << "---------------- Display content of intArray3 after modification of intArray3[0] value ----------------" << std::endl;	
	std::cout << intArray3 << std::endl;

	std::cout << "---------------- Display content of intArray1 ----------------" << std::endl;	
	std::cout << intArray1 << std::endl;

	std::cout << "---------------- Display content of const intArray5 ----------------" << std::endl;	
	std::cout << intArray5 << std::endl;

	std::cout << "---------------- Test on intArray1 with index -1 ----------------" << std::endl;	
	int index = -1;
	try{
		int value = intArray1[index];
		std::cout << "value at index " << index << " is : " << value << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------------- Test on intArray1 with index 0 ----------------" << std::endl;	
	index = 0;
	try{
		int value = intArray1[index];
		std::cout << "value at index " << index << " is : " << value << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------------- Test on intArray1 with index 9 ----------------" << std::endl;	
	index = 9;
	try{
		int value = intArray1[index];
		std::cout << "value at index " << index << " is : " << value << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------------- Test on intArray1 with index 10 ----------------" << std::endl;	
	index = 10;
	try{
		int value = intArray1[index];
		std::cout << "value at index " << index << " is : " << value << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << BOLD_RED << e.what() << NORMAL << std::endl;
	}

}