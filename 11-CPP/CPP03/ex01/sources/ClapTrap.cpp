/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:07:34 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/10 19:14:21 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("unknown")
{
	std::cout << "Default constructor ClapTrap called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Constructor ClapTrap called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment operator ClapTrap called" << std::endl;
	if (this != &src)
	{
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " attacks " << target << ", causing " \
		<< "1" << " point of damage" << NORMAL << std::endl;

		this->_energyPoints -= 1;
		this->checkHitsAndEnergyPoints();
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	count = 0;

	while (this->_energyPoints > 0 && this->_hitPoints > 0 && amount > 0)
	{
		this->_hitPoints -= 1;
		this->_attackDamage += 1;
		amount--;
		count++;
	}
	if (count > 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " was attacked and lost " \
			<< count << " hits" << NORMAL << std::endl;
		this->checkHitsAndEnergyPoints();
	}

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int	count = 0;

	while (this->_energyPoints > 0 && this->_hitPoints > 0 && amount > 0)
	{
		this->_hitPoints += 1;
		this->_energyPoints -= 1;
		amount--;
		count++;
	}
	if (count > 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " has been repaired spending " \
			<< count << " energy points" << NORMAL << std::endl;
		this->checkHitsAndEnergyPoints();
	}
	
}

std::string	ClapTrap::getName(void) const
{
	return(this->_name);
}

void	ClapTrap::displayPoints(void) const
{
	std::cout << "state of "<< this->_name << " : " << std::endl;
	std::cout << std::setw(20) << "hit points" << '|';
	std::cout << std::setw(13) << "energy points" << '|';
	std::cout << std::setw(13) << "attack damage" << std::endl;
	std::cout << std::setw(20) << this->_hitPoints << '|';
	std::cout << std::setw(13) << this->_energyPoints << '|';
	std::cout << std::setw(13) << this->_attackDamage << std::endl;
}

void ClapTrap::checkHitsAndEnergyPoints(void) const
{
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << BOLD << "ClapTrap " << this->_name << " is dead !" \
		<< NORMAL << std::endl;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << RED << BOLD << "ClapTrap " << this->_name << " has no more energy !" \
		<< NORMAL << std::endl;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor ClapTrap called" << std::endl;
}