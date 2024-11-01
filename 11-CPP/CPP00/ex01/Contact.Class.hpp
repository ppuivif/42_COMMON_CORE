#include <iostream>
#include <iomanip>

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

public:
	Contact(void);
	~Contact(void);

private:
	unsigned int	_privateContactIndex;
	std::string		_privateContactFirstName;
	std::string		_privateContactLastName;
	std::string		_privateContactNickname;
	std::string		_privateContactPhoneNumber;
	std::string		_privateContactDarkestSecret;
};

#endif