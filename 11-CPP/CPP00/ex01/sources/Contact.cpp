/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:35:49 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 10:15:38 by ppuivif          ###   ########.fr       */
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
	return (_contactIndex);
}

std::string Contact::getContactFirstName(void)const{
	return (_contactFirstName);
}

std::string Contact::getContactLastName(void)const{
	return (_contactLastName);
}

std::string Contact::getContactNickname(void)const{
	return (_contactNickname);
}

std::string Contact::getContactPhoneNumber(void)const{
	return (_contactPhoneNumber);
}

std::string Contact::getContactDarkestSecret(void)const{
	return (_contactDarkestSecret);
}

Contact::~Contact(void){
	return ;
}