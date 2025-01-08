/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:00:51 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/08 18:11:02 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
//	std::cout << "Default constructor AMateria called" << std::endl;
}

AMateria::AMateria(AMateria const &rhs)
{
	*this = rhs;
//	std::cout << "Copy constructor AMateria called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
//	std::cout << "Assignment operator AMateria called" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
//	std::cout << "Destructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
//	std::cout << "Simple constructor AMateria called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* no action on " << target.getName() << " *" << std::endl;
}