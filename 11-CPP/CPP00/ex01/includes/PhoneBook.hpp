/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:36:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/07 17:10:09 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
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

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	void				request(void);

private:
	static const int	_maxContacts = 8;
    Contact 			_contacts[_maxContacts];
    unsigned int		_nmemb = 0;
	unsigned int		_currentIndex = 0;

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
