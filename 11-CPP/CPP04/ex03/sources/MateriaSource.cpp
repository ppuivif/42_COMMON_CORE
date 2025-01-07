/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:40:03 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/07 17:32:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0 ; i < 4 ; i++)
		this->_materia[i] = NULL;
	std::cout << "Default constructor MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor MateriaSource called" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			if (this->_materia[i])
			{
				delete this->_materia[i];
				this->_materia[i] = NULL;
			}
			if (rhs._materia[i])
				this->_materia[i] = rhs._materia[i]->clone();
		}
	}
	std::cout << "Assignment operator MateriaSource called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
	std::cout << "Destructor MateriaSource called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	if (m)
	{
		while (i < 4)
		{	
			if (!this->_materia[i])
			{
				this->_materia[i] = m->clone();
				std::cout << GREEN << BOLD << "Materia " << m->getType() << " was successfully learned" << NORMAL << std::endl;
				delete m;
				break;
			}
			i++;			
		}
		if (i == 4)
			std::cout << RED << BOLD << "There is no more place to learn new Materia" << NORMAL << std::endl;
	}
	else
		std::cout << RED << BOLD << "Materia does not exist" << NORMAL << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	
	if (!type.compare("cure") || !type.compare("ice"))
	{
		while (i < 4)
		{
			if (!this->_materia[i]->getType().compare(type))
				return (this->_materia[i]->clone());
			i++;
		}
		std::cout << "There isn't any learned materia type " << type << std::endl;
		return (0);
	}
	else
	{
		std::cout << "There isn't any known materia type " << type << std::endl; 
		return (0);
	}
}