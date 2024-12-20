/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:00:51 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/20 17:59:53 by ppuivif          ###   ########.fr       */
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
