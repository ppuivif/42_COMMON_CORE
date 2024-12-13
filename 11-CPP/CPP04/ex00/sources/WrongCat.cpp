/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:50:56 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 09:27:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "default wrongcat";
	std::cout << "Default constructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor WrongCat called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
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

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "Simple constructor WrongCat called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " is meowing" << std::endl;
}
