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
	
	if (PhoneBook::_privateNmemb == 0){
		std::cout << "Phonebook is empty." << std::endl;
	}
	else{
		PhoneBook::_privateDisplayAllContacts();
		std::cout << "Chose your index : ";
		std::cin >> buff;
		PhoneBook::_privateDisplaySelectedContact(buff);
	}
}

void PhoneBook::_privateDisplayAllContacts(void){
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << std::endl;
	
	std::cout << std::setw(10) << "1" << '|';
	
	std::string first_name = "Georges";
	if (first_name.size() > 10)
		first_name.replace(first_name.begin()+9,first_name.end(),".");
	std::cout << std::setw(10) << first_name << '|';
	
	std::string last_name = "DUPONTELLES";
	if (last_name.size() > 10)
		last_name.replace(last_name.begin()+9,last_name.end(),".");
	std::cout << std::setw(10) << last_name << '|';
	
	std::string nickname = "Gege";
	if (nickname.size() > 10)
		nickname.replace(nickname.begin()+9,nickname.end(),".");
	std::cout << std::setw(10) << nickname;
	std::cout << std::endl;
}

void PhoneBook::_privateDisplaySelectedContact(std::string index){
	unsigned int num = 1;
    
	std::stringstream ss(index);
    ss >> num;
	if (ss.fail() || num > PhoneBook::_privateNmemb){
        std::cout << "\033[31m" << "Invalid input, chose a valid index" << "\033[0m" << std::endl;
		PhoneBook::_privateSearchContact();
    }
	else {
		std::cout << "First name : " << PhoneBook::_privateContacts[num - 1]._privateContactFirstName << std::endl;
		std::cout << "Last name : " << PhoneBook::_privateContacts[num - 1]._privateContactLastName << std::endl;
		std::cout << "Nickname : " << PhoneBook::_privateContacts[num - 1]._privateContactNickname << std::endl;
		std::cout << "Phone number : " << PhoneBook::_privateContacts[num - 1]._privateContactPhoneNumber << std::endl;
		std::cout << "Darkests secret : " << PhoneBook::_privateContacts[num - 1]._privateContactDarkestSecret << std::endl;
	}

}

PhoneBook::~PhoneBook(void){
	return;
}
