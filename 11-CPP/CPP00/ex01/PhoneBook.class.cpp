#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	return;
}

PhoneBook::~PhoneBook(void){
	return;
}

PhoneBook::request(void){
	std::string buff;
	std::cout << "Enter a command (ADD, SEARCH or EXIT) : ";
	std::cin >> buff;
	if (!buff.compare("ADD"))
		std::cout << "ADD" << std::endl;
	else if (!buff.compare("SEARCH"))
		std::cout << "SEARCH" << std::endl;
	else if (!buff.compare("EXIT"))
		std::cout << "EXIT" << std::endl;
	return;
}