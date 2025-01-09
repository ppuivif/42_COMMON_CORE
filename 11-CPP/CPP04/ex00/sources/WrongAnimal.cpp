/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:12:41 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 08:30:43 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "default wronganimal";
	std::cout << "Default constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor WrongAnimal called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "Assignment operator WrongAnimal called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << " is screaming" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
