#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void){
	_Nmemb = 0;
	_CurrentIndex = 0;
	_Request();
	return;
}

void	PhoneBook::_Request(void){
	std::string buff;

	while (buff.compare("EXIT") && buff.compare("exit")){
		std::cout << "Enter a command (ADD (or add), SEARCH (or search) or EXIT (or exit)) : ";
		std::cin >> buff;
		if (!buff.compare("ADD") || !buff.compare("add"))
			PhoneBook::_AddContact();
		if (!buff.compare("SEARCH") || !buff.compare("search"))
			PhoneBook::_SearchContact();
	}
	return;
}

std::string	PhoneBook::_WhitespaceHandler(std::string input){
	std::size_t index = input.find_first_of("\t");
	while (index != std::string::npos){
		input[index] = ' ';
		index = input.find_first_of("\t", index + 1);
	}
	return (input);
}

std::string	PhoneBook::_HandlePhoneNumber(void){
	std::string	input;
	char		c;

	while (input.length() != 14 && std::cin.get(c) && c != '\n'){
		if (input.length() % 3 == 0 && c != ' ')
			return ("");
		input += c;
	}
	if (c != '\n')
		return ("");
	return (input);
}

void	PhoneBook::_AddContact(void){
	Contact		newContact;
	std::string input = "";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (input == ""){
		std::cout << "Enter contact first name : ";
		std::getline(std::cin, input);
		newContact.set_ContactFirstName(input);
	}

	input = "";
	while (input == ""){
		std::cout << "Enter contact last name : ";
		std::getline(std::cin, input);
		newContact.set_ContactLastName(input);
	}

	input = "";
	while (input == ""){
		std::cout << "Enter contact nickname : ";
		std::getline(std::cin, input);
		newContact.set_ContactNickname(input);
	}

	input = "";
	while (input == ""){
		std::cout << "Enter contact phone number according to format \"00 00 00 00 00\" : ";
		input = _HandlePhoneNumber();
		newContact.set_ContactPhoneNumber(input);
	}

	input = "";
	while (input == ""){
		std::cout << "Enter contact darkest secret : ";
		std::getline(std::cin, input);
		newContact.set_ContactDarkestSecret(input);
	}

	newContact.set_ContactIndex(_CurrentIndex);
	_Contacts[_CurrentIndex] = newContact;
	_Nmemb++;
	if (_CurrentIndex < 8)
		_CurrentIndex++;
	else
		_CurrentIndex = 0;
}

void PhoneBook::_SearchContact(void){
	std::string buff;
	
	if (PhoneBook::_Nmemb == 0){
		std::cout << "Phonebook is empty." << std::endl;
	}
	else{
		PhoneBook::_DisplayAllContacts();
		std::cout << "Chose your index : ";
		std::cin >> buff;
		PhoneBook::_DisplaySelectedContact(buff);
	}
}

void PhoneBook::_DisplayAllContacts(void){
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << std::endl;

	for(unsigned int i = 0; i < _Nmemb; i++){
		std::cout << std::setw(10) << _Contacts[i].get_ContactIndex() << '|';
	
		std::string	contactFirstName = _WhitespaceHandler(_Contacts[i].get_ContactFirstName());
		if (contactFirstName.size() > 10)
			contactFirstName.replace(contactFirstName.begin()+9, contactFirstName.end(),".");
		std::cout << std::setw(10) << contactFirstName << '|';

		std::string	contactLastName = _WhitespaceHandler(_Contacts[i].get_ContactLastName());
		if (contactLastName.size() > 10)
			contactLastName.replace(contactLastName.begin()+9, \
				contactLastName.end(),".");
		std::cout << std::setw(10) << contactLastName << '|';

		std::string	contactNickname = _WhitespaceHandler(_Contacts[i].get_ContactNickname());
		if (contactNickname.size() > 10)
			contactNickname.replace(contactNickname.begin()+9, contactNickname.end(),".");
		std::cout << std::setw(10) << contactNickname;
		std::cout << std::endl;
	}
}

void PhoneBook::_DisplaySelectedContact(std::string index){
	unsigned int num = 1;
    
	std::stringstream ss(index);
    ss >> num;
	if (ss.fail() || num > PhoneBook::_Nmemb || num == 0){
        std::cout << "\033[31m" << "Invalid input, chose a valid index" << "\033[0m" << std::endl;
		PhoneBook::_SearchContact();
    }
	else {
		std::cout << "First name : " << _Contacts[num - 1].get_ContactFirstName() << std::endl;
		std::cout << "Last name : " << _Contacts[num - 1].get_ContactLastName() << std::endl;
		std::cout << "Nickname : " << _Contacts[num - 1].get_ContactNickname() << std::endl;
		std::cout << "Phone number : " << _Contacts[num - 1].get_ContactPhoneNumber() << std::endl;
		std::cout << "Darkests secret : " << _Contacts[num - 1].get_ContactDarkestSecret() << std::endl;
	}

}

PhoneBook::~PhoneBook(void){
	return;
}
