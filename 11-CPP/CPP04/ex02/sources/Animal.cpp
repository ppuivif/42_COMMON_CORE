/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:12:41 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 18:03:44 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	this->_type = "default animal";
	std::cout << "Default constructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor AAnimal called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "Assignment operator AAnimal called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Simple constructor AAnimal called" << std::endl;
}

void AAnimal::makeSound(void) const
{
	std::cout << this->getType() << " is speaking out" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

std::string	toString(int nb)
{
	std::ostringstream	oss;

	oss << nb;
	return (oss.str());
}
