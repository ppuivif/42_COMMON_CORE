/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:00:51 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/16 18:16:12 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor AMateria called" << std::endl;
}

AMateria & AMateria::operator=(const AMateria & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Assignment operator AMateria called" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called" << std::endl;
}

AMateria::AMateria(const std::string & type) : _type(type)
{
	std::cout << "Simple constructor AMateria called" << std::endl;
}

const std::string & AMateria::getType() const
{
	return (this->_type);
}

AMateria *AMateria::clone() const
{
	AMateria *clone;

	clone = new AMateria(*this);
	return (clone);
}

//void AMateria::use(ICharacter & target)
void AMateria::use(std::string target)
{
	if (!this->_type.compare("ice"))
		std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
	if (!this->_type.compare("cure"))
		std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
