/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:49:44 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/22 09:54:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

void	HumanB::attack(void)const
{
	if (!this->_weapon->getType().empty())
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have any weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}


HumanB::~HumanB()
{

}
