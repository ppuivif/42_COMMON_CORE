/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:50:56 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 11:11:08 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "default wrongcat";
	std::cout << "Default constructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &rhs) : WrongAnimal()
{
	*this = rhs;
	std::cout << "Copy constructor WrongCat called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	std::cout << "Assignment operator WrongCat called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " is wrong meowing" << std::endl;
}
