/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:09 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:58:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
//	std::cout << "Default constructor Cure called" << std::endl;
}

Cure::Cure(Cure const & rhs) : AMateria(rhs)
{
//	std::cout << "Copy constructor Cure called" << std::endl;
}

Cure &Cure::operator=(Cure const & rhs)
{
	if (this != &rhs)
	 	this->AMateria::operator=(rhs);
 //	std::cout << "Assignment operator Cure called" << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
//	std::cout << "Destructor Cure called" << std::endl;
}

AMateria *Cure::clone(void) const
{
	Cure	*clone;

	clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter & target)
{
	if (!this->_type.compare("cure"))
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

