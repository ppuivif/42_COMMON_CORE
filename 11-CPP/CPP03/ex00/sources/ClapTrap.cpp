/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:07:34 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/22 18:43:35 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << RED << "ClapTrap " << this->_name << " attacks " << target << ", causing " \
	<< "damage" << " points of damage" << NORMAL << std::endl;

	this->_energyPoints -= 1;
	this->displayPoints();
//	target._hitPoints -= 1;
//	target.displayPoints();

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << RED << "ClapTrap" << this->_name << "was attacked and lost " \
	<< amount << " energy points" << NORMAL << std::endl;

	this->_hitPoints -= amount;
	this->_attackDamage += amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << GREEN << "ClapTrap" << this->_name << "is repaired spending " \
	<< amount << " energy points" << NORMAL << std::endl;

	this->_energyPoints -= amount;
	this->_hitPoints += amount;
}

std::string	ClapTrap::getName(void) const
{
	return(this->_name);
}


void	ClapTrap::displayPoints() const
{
	std::cout << std::endl;
	std::cout << "state of "<< this->_name << std::endl;
	std::cout << std::setw(10) << "hit points" << '|';
	std::cout << std::setw(13) << "energy points" << '|';
	std::cout << std::setw(13) << "attack damage" << std::endl;
	std::cout << std::setw(10) << this->_hitPoints << '|';
	std::cout << std::setw(13) << this->_energyPoints << '|';
	std::cout << std::setw(13) << this->_attackDamage << std::endl;
	std::cout << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}