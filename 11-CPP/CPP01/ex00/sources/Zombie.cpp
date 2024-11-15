/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:28:12 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 11:58:13 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

void	Zombie::announce(void)const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string name)
{
	this->_name = name;
}

std::string	Zombie::getZombieName(void)const
{
	return (this->_name);
}

Zombie::~Zombie(void)
{
	std::cout << this->getZombieName() << " has been destroyed" << std::endl << std::endl;
	return ;
}
