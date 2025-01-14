/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:04:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/11 17:20:08 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default", 100, 50, 20)
{
	std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	*this = src; 
	std::cout << "Copy constructor ScavTrap called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Simple constructor ScavTrap " << this->_name << " called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is now in Gate Keeper Mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << RED << this->_name << " attacks " << target << ", causing " \
		<< "1" << " point of damage" << NORMAL << std::endl;
		this->checkHitsAndEnergyPoints();
	}
}

