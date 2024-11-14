/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:36:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/14 17:20:55 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#ifndef RED
# define RED "\033[31m"
# endif
#ifndef BOLD
# define BOLD "\033[1m"
# endif
#ifndef NORMAL
# define NORMAL "\033[0m"
# endif

class PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);
	void				request(void);

private:
    Contact 			_contacts[8];
    unsigned int		_nmemb;
	unsigned int		_currentIndex;
	unsigned int		_eof;

	int					_addContact(void);
	int					_searchContact(void);
	void				_displayAllContacts(void);
	void				_displaySelectedContact(std::string index);
	std::string			_whitespaceHandler(std::string input);
	std::string			_getValidInput(void);
	std::string			_handlePhoneNumber(void);
	int					_checkSpacesAndDigits(std::string input);

};

#endif
