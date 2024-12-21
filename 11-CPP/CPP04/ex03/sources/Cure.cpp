/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:09 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/21 17:51:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
//	this->_type = "cure";
	std::cout << "Default constructor Cure called" << std::endl;
}

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
//	*this = rhs;
	std::cout << "Copy constructor Cure called" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
//		this->_type = rhs._type;
	 	this->AMateria::operator=(rhs);
 	std::cout << "Assignment operator Cure called" << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Destructor Cure called" << std::endl;
}

Cure *Cure::clone(void) const
{
	Cure	*clone;

	clone = new Cure(*this);
	return (clone);
}

//void Cure::use(ICharacter& target)
void Cure::use(std::string target)
{
	if (!this->_type.compare("cure"))
		std::cout << "* heals " << target << "'s wounds *" << std::endl;
}

