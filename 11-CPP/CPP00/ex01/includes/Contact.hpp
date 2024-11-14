/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:36:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/14 17:20:59 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

public:
	Contact(void);
	~Contact(void);
	void			setContactIndex(unsigned int index);
	void			setContactFirstName(const std::string firstName);
	void			setContactLastName(const std::string lastName);
	void			setContactNickname(const std::string nickname);
	void			setContactPhoneNumber(const std::string phoneNumber);
	void			setContactDarkestSecret(const std::string darkestSecret);
	unsigned int	getContactIndex(void)const;
	std::string		getContactFirstName(void)const;
	std::string		getContactLastName(void)const;
	std::string		getContactNickname(void)const;
	std::string		getContactPhoneNumber(void)const;
	std::string		getContactDarkestSecret(void)const;

private:
	unsigned int	_contactIndex;
	std::string		_contactFirstName;
	std::string		_contactLastName;
	std::string		_contactNickname;
	std::string		_contactPhoneNumber;
	std::string		_contactDarkestSecret;
};

#endif
