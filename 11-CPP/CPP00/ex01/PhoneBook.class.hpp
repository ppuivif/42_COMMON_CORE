#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.Class.hpp"

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

private:
	static const int	_privateMaxContacts = 8;
    Contact 			_privateContacts[_privateMaxContacts];
    unsigned int		_privateNmemb = 0;

	void	_privateRequest(void);
	void	_privateAddContact(void);
	void	_privateSearchContact(void);
	void	_privateDisplayAllContacts(void);
	void	_privateDisplaySelectedContact(std::string index);
};

#endif