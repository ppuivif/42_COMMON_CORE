#include <iostream>
#include <iomanip>
#include <sstream>

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

private:
	void	_privateRequest(void);
	void	_privateAddContact(void);
	void	_privateSearchContact(void);
	void	_privateDisplayContact(std::string index);
};

#endif