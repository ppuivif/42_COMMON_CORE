/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:12:41 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/12 18:56:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "default animal";
	std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Animal called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "Assignment operator Animal called" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Destructor Animal called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Simple constructor Animal called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << this->getType() << " is speaking out" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
