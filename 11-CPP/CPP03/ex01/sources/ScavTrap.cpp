/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:04:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/24 16:14:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Constructor ScavTrap called" << std::endl;
	ClapTrap instance;
	return ;
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
