/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:28:12 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/25 09:51:09 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

void	Zombie::announce(void)const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getZombieName(void)const
{
	return (this->_name);
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed" << std::endl << std::endl;
	return;
}
