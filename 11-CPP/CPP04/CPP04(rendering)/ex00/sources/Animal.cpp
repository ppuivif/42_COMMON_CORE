/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:12:41 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 11:50:42 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "default animal";
	std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(Animal const & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Animal called" << std::endl;
}

Animal &Animal::operator=(Animal const & rhs)
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

Animal::Animal(std::string const & type) : _type(type)
{
	std::cout << "Simple constructor Animal called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << this->getType() << " is speaking out" << std::endl;
}
