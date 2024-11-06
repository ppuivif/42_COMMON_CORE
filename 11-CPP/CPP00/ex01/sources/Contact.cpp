/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:35:49 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/06 16:46:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void){
	_ContactIndex = 0;
	return;
}

void	Contact::set_ContactIndex(unsigned int index){
	_ContactIndex = index + 1;
}

void	Contact::set_ContactFirstName(std::string contactFirstName){
	_ContactFirstName = contactFirstName;
}

void	Contact::set_ContactLastName(std::string contactLastName){
	_ContactLastName = contactLastName;
}

void	Contact::set_ContactNickname(std::string contactNickname){
	_ContactNickname = contactNickname;
}

void	Contact::set_ContactPhoneNumber(std::string contactPhoneNumber){
	_ContactPhoneNumber = contactPhoneNumber;
}

void	Contact::set_ContactDarkestSecret(std::string contactDarkestSecret){
	_ContactDarkestSecret = contactDarkestSecret;
}

unsigned int	Contact::get_ContactIndex(void)const{
	return(Contact::_ContactIndex);
}

std::string Contact::get_ContactFirstName(void)const{
	return(Contact::_ContactFirstName);
}

std::string Contact::get_ContactLastName(void)const{
	return(Contact::_ContactLastName);
}

std::string Contact::get_ContactNickname(void)const{
	return(Contact::_ContactNickname);
}

std::string Contact::get_ContactPhoneNumber(void)const{
	return(Contact::_ContactPhoneNumber);
}

std::string Contact::get_ContactDarkestSecret(void)const{
	return(Contact::_ContactDarkestSecret);
}

Contact::~Contact(void){
	return;
}