/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:09 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:59:41 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
//	std::cout << "Default constructor Ice called" << std::endl;
}

Ice::Ice(Ice const & rhs) : AMateria(rhs)
{
//	std::cout << "Copy constructor Ice called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
	 	this->AMateria::operator=(rhs);
// 	std::cout << "Assignment operator Ice called" << std::endl;
	return (*this);
}

Ice::~Ice(void)
{
//	std::cout << "Destructor Ice called" << std::endl;
}

AMateria *Ice::clone(void) const
{
	Ice	*clone;
	
	clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter & target)
{
	if (!this->_type.compare("ice"))
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

