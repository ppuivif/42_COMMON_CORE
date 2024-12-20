/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:09 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/20 18:26:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria(void)
{
	this->_type = "ice";
	std::cout << "Default constructor Ice called" << std::endl;
}

Ice::Ice(const Ice &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Ice called" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Assignment operator Ice called" << std::endl;
	return (*this)
}

Ice::~Ice(void)
{
	std::cout << "Destructor Ice called" << std::endl;
}

Ice *Ice::clone(void) const
{
	Ice	*clone;

	clone = new Ice(*this);
	return (clone);
}

void Ice::use(std::string target)
{
	if (!this->_type.compare("ice"))
		std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
	if (!this->_type.compare("cure"))
		std::cout << "* heals " << target << "'s wounds *" << std::endl;
}

