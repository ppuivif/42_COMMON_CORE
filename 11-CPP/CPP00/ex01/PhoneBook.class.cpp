#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	_privateRequest();
	return;
}

void PhoneBook::_privateRequest(void){
	std::string buff;

	while (buff.compare("EXIT")){
		std::cout << "Enter a command (ADD, SEARCH or EXIT) : ";
		std::cin >> buff;
		if (!buff.compare("ADD"))
			std::cout << "ADD" << std::endl;
		if (!buff.compare("SEARCH")){
			std::cout << "SEARCH" << std::endl;
			PhoneBook::_privateSearchContact();
		}
	}
	return;
}

void PhoneBook::_privateSearchContact(void){
	std::string buff;

	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << std::endl;
	
	std::cout << std::setw(10) << "1" << '|';
	std::cout << std::setw(10) << "Georges" << '|';
	std::string str = "DUPONTELLES";
	if (str.size() > 10)
		str.replace(str.begin()+9,str.end(),".");
	std::cout << std::setw(10) << str << '|';
	std::cout << std::setw(10) << "Gege";
	std::cout << std::endl;
	
	std::cout << "Chose your index : ";
	std::cin >> buff;
	PhoneBook::_privateDisplayContact(buff);
}

void PhoneBook::_privateDisplayContact(std::string index){
	unsigned int num;
    
	std::stringstream ss(index);
    ss >> num;
	if (ss.fail() || num > 10){
        std::cout << "\033[31m" << "Invalid input, chose a valid index" << "\033[0m" << std::endl;
		PhoneBook::_privateSearchContact();
    }
	else
		std::cout << index << std::endl;

}

PhoneBook::~PhoneBook(void){
	return;
}
