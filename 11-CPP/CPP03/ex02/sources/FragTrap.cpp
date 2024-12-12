/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:04:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/11 16:53:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default", 100, 100, 30)
{
	std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
	*this = src; 
	std::cout << "Copy constructor FragTrap called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	std::cout << "Copy assignment operator FragTrap called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor FragTrap " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Simple constructor FragTrap " << this->_name << " called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Hey guys " << this->_name << " request a high-fives !" << std::endl;
}
