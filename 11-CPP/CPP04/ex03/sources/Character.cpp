/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:58:17 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/06 18:48:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default constructor Character called" << std::endl;
}

Character::Character(Character const & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Character called" << std::endl;
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0 ; i < 4 ; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	std::cout << "Assignment operator Character called" << std::endl;
	return (*this);
}

Character::~Character()
{
	std::cout << "Destructor Character called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = NULL;
	std::cout << "Simple constructor Character called" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	int		i = 0;
	
	if (m)
	{
		while (i < 4)
		{	
			if (!this->_inventory[i])
			{
				this->_inventory[i] = m;
				std::cout << "Slot number " << i << " was successfully equiped with " << m->getType() << " Materia" << std::endl;
				break;
			}
			i++;			
		}
		if (i == 4)
			std::cout << "No more slot for new Materia" << std::endl;
	}
	else
		std::cout << RED << BOLD << "Materia does not exist" << NORMAL << std::endl;
}

void Character::unequip(int idx)
{
	std::cout << "Slot number " << idx << " was successfully unequiped with " << "m" << " Materia" << std::endl;
}

void Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx > 3)
		std::cout << RED << BOLD << "You tried to use a Materia but slot " << idx << " does not exist" << NORMAL << std::endl;
	else if (!this->_inventory[idx])
		std::cout << RED << BOLD << "You tried to use a Materia but there isn't any available Materia on slot " << idx << NORMAL << std::endl;
	else if (this->_inventory[idx]->getType() == "default")
		std::cout << RED << BOLD << "You tried to use a Materia but Materia on slot " << idx << " is empty" << NORMAL << std::endl;
	else
		this->_inventory[idx]->use(target);
}
