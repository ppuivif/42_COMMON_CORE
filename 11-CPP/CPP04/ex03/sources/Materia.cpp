/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:00:51 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/23 11:22:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor AMateria called" << std::endl;
}

AMateria::AMateria(AMateria const &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor AMateria called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
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

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "Simple constructor AMateria called" << std::endl;
}

const std::string & AMateria::getType() const
{
	return (this->_type);
}

//void AMateria::use(ICharacter& target)
void use(std::string target)
{
	std::cout << "* no action on " << target << " *" << std::endl;
}