/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:29:30 by ppuivif           #+#    #+#             */
/*   Updated: 2024/10/30 22:38:59 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
//#include "Contact.class.hpp"

int main(){
	PhoneBook instance;
	instance.request(void);
		
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << std::endl;
	
	std::cout << std::setw(10) << "1" << '|';
	std::cout << std::setw(10) << "Georges" << '|';
	std::string str = "DUPONTELLES";
	if (str.size() > 10)
		str.replace(str.begin()+9,str.end(),".");
	std::cout << std::setw(10) << str << '|';
	std::cout << std::setw(10) << "Gege";
	std::cout << std::endl;
	return (0);
}