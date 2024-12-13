/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:41:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 17:23:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), Brain()
{
	this->_type = "default dog";
	this->_brain = new Brain();
	std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = rhs._brain;
	}
	std::cout << "Assignment operator Dog called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->_brain = new Brain();
	std::cout << "Simple constructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() << " is barking" << std::endl;
}

