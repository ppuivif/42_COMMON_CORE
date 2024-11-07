/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:35:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/07 17:09:41 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	return;
}

void	PhoneBook::request(void){
	std::string input;

	while (input.compare("EXIT")){
		std::cout << BOLD << "Enter a command (ADD, SEARCH or EXIT) : " << NORMAL;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input.compare("EXIT") && input.compare("ADD") && input.compare("SEARCH"))
			std::cout << RED << "Command invalid" << NORMAL << std::endl;
		if (!input.compare("ADD")){
			std::cout << std::endl;	
			if (PhoneBook::_addContact())
				break ;
		}
		if (!input.compare("SEARCH")){
			if (PhoneBook::_searchContact())
				break ;
		}
	}
	return;
}

std::string	PhoneBook::_whitespaceHandler(std::string input){
	std::size_t index = input.find_first_of("\t");
	while (index != std::string::npos){
		input[index] = ' ';
		index = input.find_first_of("\t", index + 1);
	}
	return (input);
}

int PhoneBook::_checkSpacesAndDigits(std::string input){
	for (size_t i = 1; i <= input.length(); i++){
		if ((i % 3 == 0 && input[i - 1] != ' ' ) || (i % 3 != 0 && !isdigit(input[i - 1])))
			return (1);
	}
	return (0);
}

std::string	PhoneBook::_handlePhoneNumber(void){
	std::string	input;

	while (1){
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (input);
		if (input.empty() || input.length() != 14 || _checkSpacesAndDigits(input))
			std::cout << RED << "Enter a valid input (according to format \"00 00 00 00 00\" : " << NORMAL;
		else
			return (input);
	}
}

std::string	PhoneBook::_getValidInput(void){
	std::string input;
	
	while (input.empty()){
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (input);
		if (input.empty())
			std::cout << RED << "Enter a valid input (non empty) : " << NORMAL;
	}
	return (input);
}

int	PhoneBook::_addContact(void){
	Contact		newContact;
	std::string tmp;

	std::cout << BOLD << "Enter contact first name : " << NORMAL;
	tmp = _getValidInput();
	if (tmp.empty())
		return (1);
	newContact.setContactFirstName(tmp);

	std::cout << BOLD << "Enter contact last name : " << NORMAL;
	tmp = _getValidInput();
	if (tmp.empty())
		return (1);
	newContact.setContactLastName(tmp);
	
	std::cout << BOLD << "Enter contact nickname : " << NORMAL;
	tmp = _getValidInput();
	if (tmp.empty())
		return (1);
	newContact.setContactNickname(tmp);
	
	std::cout << BOLD << "Enter contact phone number according to format \"00 00 00 00 00\" : " << NORMAL;
	tmp = _handlePhoneNumber();
	if (tmp.empty())
		return (1);
	newContact.setContactPhoneNumber(tmp);

	std::cout << BOLD << "Enter contact darkest secret : " << NORMAL;
	tmp = _getValidInput();
	if (tmp.empty())
		return (1);
	newContact.setContactDarkestSecret(tmp);
	
	newContact.setContactIndex(_currentIndex);
	_contacts[_currentIndex] = newContact;
	
	if (_nmemb != _maxContacts)
		_nmemb++;
	if (_currentIndex != _maxContacts - 1)
		_currentIndex++;
	else
		_currentIndex = 0;

	std::cout << std::endl;	
	return (0);
}

void PhoneBook::_displayAllContacts(void){

	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << std::endl;

	for(unsigned int i = 0; i < _nmemb; i++){
		std::cout << std::setw(10) << _contacts[i].getContactIndex() << '|';
	
		std::string	contactFirstName = _whitespaceHandler(_contacts[i].getContactFirstName());
		if (contactFirstName.size() > 10)
			contactFirstName.replace(contactFirstName.begin() + 9, contactFirstName.end(), ".");
		std::cout << std::setw(10) << contactFirstName << '|';

		std::string	contactLastName = _whitespaceHandler(_contacts[i].getContactLastName());
		if (contactLastName.size() > 10)
			contactLastName.replace(contactLastName.begin() + 9, \
				contactLastName.end(), ".");
		std::cout << std::setw(10) << contactLastName << '|';

		std::string	contactNickname = _whitespaceHandler(_contacts[i].getContactNickname());
		if (contactNickname.size() > 10)
			contactNickname.replace(contactNickname.begin() + 9, contactNickname.end(), ".");
		std::cout << std::setw(10) << contactNickname;
		std::cout << std::endl;
	}
}

int	PhoneBook::_searchContact(void){
	std::string input;
	
	if (PhoneBook::_nmemb == 0){
		std::cout << RED << "Phonebook is empty." << NORMAL << std::endl;
	}
	else{
		PhoneBook::_displayAllContacts();
		std::cout << std::endl;
		std::cout << BOLD << "Chose your index : " << NORMAL;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		std::cout << std::endl;	
		PhoneBook::_displaySelectedContact(input);
	}
	return (0);
}

void PhoneBook::_displaySelectedContact(std::string contactIndex){
	unsigned int index = 1;
    
	std::stringstream ss(contactIndex);
    ss >> index;
	if (ss.fail() || index > _nmemb || index == 0){
        std::cout << RED << "Invalid input, chose a valid index" << NORMAL << std::endl;
		PhoneBook::_searchContact();
    }
	else {
		std::cout << BOLD << "First name : " << NORMAL << _contacts[index - 1].getContactFirstName() << std::endl;
		std::cout << BOLD << "Last name : " << NORMAL << _contacts[index - 1].getContactLastName() << std::endl;
		std::cout << BOLD << "Nickname : " << NORMAL << _contacts[index - 1].getContactNickname() << std::endl;
		std::cout << BOLD << "Phone number : " << NORMAL << _contacts[index - 1].getContactPhoneNumber() << std::endl;
		std::cout << BOLD << "Darkest secret : " << NORMAL << _contacts[index - 1].getContactDarkestSecret() << std::endl;
		std::cout << std::endl;	
	}

}

PhoneBook::~PhoneBook(void){
	return;
}
