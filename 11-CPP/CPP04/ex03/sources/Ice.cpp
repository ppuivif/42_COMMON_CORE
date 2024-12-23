/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:09 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/23 11:10:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
//	this->_type = "ice";
	std::cout << "Default constructor Ice called" << std::endl;
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
//	*this = rhs;
	std::cout << "Copy constructor Ice called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
//		this->_type = rhs._type;
	 	this->AMateria::operator=(rhs);
 	std::cout << "Assignment operator Ice called" << std::endl;
	return (*this);
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

//void Ice::use(ICharacter& target)
void Ice::use(std::string target)
{
	if (!this->_type.compare("ice"))
		std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}

