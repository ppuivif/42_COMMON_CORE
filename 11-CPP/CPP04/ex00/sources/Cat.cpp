/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:50:56 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 09:14:34 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "default cat";
	std::cout << "Default constructor Cat called" << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "Assignment operator Cat called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Simple constructor Cat called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() << " is meowing" << std::endl;
}
