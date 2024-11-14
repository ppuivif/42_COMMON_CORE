/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:35:49 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/14 14:54:56 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

void	Contact::setContactIndex(unsigned int index)
{
	this->_contactIndex = index + 1;
}

void	Contact::setContactFirstName(std::string contactFirstName)
{
	this->_contactFirstName = contactFirstName;
}

void	Contact::setContactLastName(std::string contactLastName)
{
	this->_contactLastName = contactLastName;
}

void	Contact::setContactNickname(std::string contactNickname)
{
	this->_contactNickname = contactNickname;
}

void	Contact::setContactPhoneNumber(std::string contactPhoneNumber)
{
	this->_contactPhoneNumber = contactPhoneNumber;
}

void	Contact::setContactDarkestSecret(std::string contactDarkestSecret)
{
	this->_contactDarkestSecret = contactDarkestSecret;
}

unsigned int	Contact::getContactIndex(void)const
{
	return (this->_contactIndex);
}

std::string Contact::getContactFirstName(void)const
{
	return (this->_contactFirstName);
}

std::string Contact::getContactLastName(void)const
{
	return (this->_contactLastName);
}

std::string Contact::getContactNickname(void)const
{
	return (this->_contactNickname);
}

std::string Contact::getContactPhoneNumber(void)const
{
	return (this->_contactPhoneNumber);
}

std::string Contact::getContactDarkestSecret(void)const
{
	return (this->_contactDarkestSecret);
}

Contact::~Contact(void)
{
	return ;
}