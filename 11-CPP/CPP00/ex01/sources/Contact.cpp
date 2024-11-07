/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:35:49 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/07 17:12:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void){
	return ;
}

void	Contact::setContactIndex(unsigned int index){
	_contactIndex = index + 1;
}

void	Contact::setContactFirstName(std::string contactFirstName){
	_contactFirstName = contactFirstName;
}

void	Contact::setContactLastName(std::string contactLastName){
	_contactLastName = contactLastName;
}

void	Contact::setContactNickname(std::string contactNickname){
	_contactNickname = contactNickname;
}

void	Contact::setContactPhoneNumber(std::string contactPhoneNumber){
	_contactPhoneNumber = contactPhoneNumber;
}

void	Contact::setContactDarkestSecret(std::string contactDarkestSecret){
	_contactDarkestSecret = contactDarkestSecret;
}

unsigned int	Contact::getContactIndex(void)const{
	return (Contact::_contactIndex);
}

std::string Contact::getContactFirstName(void)const{
	return (Contact::_contactFirstName);
}

std::string Contact::getContactLastName(void)const{
	return (Contact::_contactLastName);
}

std::string Contact::getContactNickname(void)const{
	return (Contact::_contactNickname);
}

std::string Contact::getContactPhoneNumber(void)const{
	return (Contact::_contactPhoneNumber);
}

std::string Contact::getContactDarkestSecret(void)const{
	return (Contact::_contactDarkestSecret);
}

Contact::~Contact(void){
	return ;
}