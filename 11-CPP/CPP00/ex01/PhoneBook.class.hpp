#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include "Contact.Class.hpp"

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

private:
	static const int	_MaxContacts = 8;
    Contact 			_Contacts[_MaxContacts];
    unsigned int		_Nmemb;
	unsigned int		_CurrentIndex;

	void		_Request(void);
	void		_AddContact(void);
	void		_SearchContact(void);
	void		_DisplayAllContacts(void);
	void		_DisplaySelectedContact(std::string index);
	std::string	_WhitespaceHandler(std::string input);
	std::string	_HandlePhoneNumber(void);

};

#endif