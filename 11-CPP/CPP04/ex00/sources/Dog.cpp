/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:41:53 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 11:10:49 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "default dog";
	std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(Dog const &rhs) : Animal()
{
	*this = rhs;
	std::cout << "Copy constructor Dog called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "Assignment operator Dog called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Simple constructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() << " is barking" << std::endl;
}

