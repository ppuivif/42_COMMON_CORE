/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:36:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/06 18:21:34 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include "Contact.hpp"

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#ifndef RED
# define RED "\033[31m"
# endif
#ifndef WHITE
# define WHITE "\033[0m"
# endif

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

private:
	static const int	_MaxContacts = 3;
    Contact 			_Contacts[_MaxContacts];
    unsigned int		_Nmemb;
	unsigned int		_CurrentIndex;

	void		_Request(void);
	void		_AddContact(void);
	void		_SearchContact(void);
	void		_DisplayAllContacts(void);
	void		_DisplaySelectedContact(std::string index);
	std::string	_WhitespaceHandler(std::string input);
	std::string	_GetValidInput(const std::string error_message);
	std::string	_HandlePhoneNumber(void);

};

#endif