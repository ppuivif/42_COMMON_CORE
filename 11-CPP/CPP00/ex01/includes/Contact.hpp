/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:36:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/06 16:36:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

public:
	Contact(void);
	~Contact(void);
	void			set_ContactIndex(unsigned int index);
	void			set_ContactFirstName(const std::string firstName);
	void			set_ContactLastName(const std::string lastName);
	void			set_ContactNickname(const std::string nickname);
	void			set_ContactPhoneNumber(const std::string phoneNumber);
	void			set_ContactDarkestSecret(const std::string darkestSecret);
	unsigned int	get_ContactIndex(void)const;
	std::string		get_ContactFirstName(void)const;
	std::string		get_ContactLastName(void)const;
	std::string		get_ContactNickname(void)const;
	std::string		get_ContactPhoneNumber(void)const;
	std::string		get_ContactDarkestSecret(void)const;

private:
	unsigned int	_ContactIndex;
	std::string		_ContactFirstName;
	std::string		_ContactLastName;
	std::string		_ContactNickname;
	std::string		_ContactPhoneNumber;
	std::string		_ContactDarkestSecret;
};

#endif