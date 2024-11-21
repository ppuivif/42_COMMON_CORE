/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:07:34 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/20 17:45:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << "target" << ", causing " \
	<< "damage" << " points of damage" << std::endl;

	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap" << this->_name << "was attacked and lost " \
	<< amount << " energy points" << std::endl;

	this->_hitPoints -= amount;
	this->_attackDamage += amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" << this->_name << "is repaired spending " \
	<< amount << " energy points" << std::endl;

	this->_energyPoints -= amount;
	this->_hitPoints += amount;
}


ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}