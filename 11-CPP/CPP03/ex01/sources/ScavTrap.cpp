/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:04:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/10 19:11:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _name("unknown")
{
	std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name)
{
	std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl;
	*this = src; 
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	if (this != &src)
	{
		std::cout << "Copy assignment operator ScavTrap called" << std::endl;
//		this->
	}
}

void	guardGate(void)
{
	std::cout << "ScavTrap is now in Gate Keeper Mode" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap called" << std::endl;
	return ;
}
