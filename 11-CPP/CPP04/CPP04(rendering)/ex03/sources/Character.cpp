/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:58:17 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:55:49 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = NULL;
	this->_indexInTrash = 0;
//	std::cout << "Default constructor Character called" << std::endl;
}

Character::Character(Character const & rhs)
{
	*this = rhs;
//	std::cout << "Copy constructor Character called" << std::endl;
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
//	std::cout << "Assignment operator Character called" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (int i = 0 ; i < this->_indexInTrash ; i++)
	{
		if (this->_materiaListForTrash[i])
			delete this->_materiaListForTrash[i];
	}
//	std::cout << "Destructor Character called for " << this->getName() << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = NULL;
	this->_indexInTrash = 0;
//	std::cout << "Simple constructor Character called" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria * m)
{
	int		i = 0;
	
	if (m)
	{
		while (i < 4)
		{	
			if (!this->_inventory[i])
			{
				this->_inventory[i] = m;
				std::cout << GREEN << BOLD << "For " << this->getName() << ", slot number " << i << " was successfully equiped with " << m->getType() << " Materia." << NORMAL << std::endl;
				for (int i = 0 ; i < this->_indexInTrash ; i++)
				{
					if (this->_materiaListForTrash[i] && this->_materiaListForTrash[i] == m)
						this->_materiaListForTrash[i] = NULL;
				}
				break;
			}
			i++;			
		}
		if (i == 4)
		{
			std::cout << RED << BOLD << "There is no more slot on " << this->getName() << " for new Materia." << NORMAL << std::endl;
			if (this->unequipedMateriaStoring(m) == 0)
			{
				std::cout << GREEN << BOLD << "For " << this->getName() << ", " << m->getType() << " Materia" << " was successfully layed on the floor." << NORMAL << std::endl;
			}
			else
			{
				std::cout << RED << BOLD <<  "For " << this->getName() << ", " << m->getType() << " Materia" << " couldn't be layed on the floor and was deleted." << NORMAL << std::endl;
				delete m;
			}
				
		}
	}
	else
		std::cout << RED << BOLD << "Materia does not exist." << NORMAL << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << RED << BOLD << "You tried to unequip a Materia but slot " << idx << " does not exist." << NORMAL << std::endl;
	else if (!this->_inventory[idx])
		std::cout << RED << BOLD << "You tried to unequip a Materia but there isn't any available Materia on slot " << idx << "." << NORMAL << std::endl;
	else
	{
		std::string tmp_type = this->_inventory[idx]->getType();
		if (this->unequipedMateriaStoring(this->_inventory[idx]) == 0)
		{
			this->_inventory[idx] = NULL;
			std::cout << GREEN << BOLD << "For " << this->getName() << ", " << tmp_type << " Materia" << " was successfully unequiped on slot number " << idx << "." << NORMAL << std::endl;
		}
		else
			std::cout << RED << BOLD <<  "For " << this->getName() << ", " << tmp_type << " Materia" << " couldn't be unequiped on slot number " << idx << "." << NORMAL << std::endl;
	}
}

int Character::unequipedMateriaStoring(AMateria * m)
{
	if (this->_indexInTrash >= TRASH_SIZE)
	{
		std::cout << RED << BOLD << "The trash reached its maximum size." << std::endl << "You must redefine its size to collect the unequiped Materia." << NORMAL << std::endl;
		return (1);
	}
	this->_materiaListForTrash[this->_indexInTrash] = m;
	this->_indexInTrash += 1;
	return (0);
}

void Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx > 3)
		std::cout << RED << BOLD << "You tried to use a Materia but slot " << idx << " does not exist" << NORMAL << std::endl;
	else if (!this->_inventory[idx])
		std::cout << RED << BOLD << "You tried to use a Materia but there isn't any available Materia on slot " << idx << NORMAL << std::endl;
	else
		this->_inventory[idx]->use(target);
}
