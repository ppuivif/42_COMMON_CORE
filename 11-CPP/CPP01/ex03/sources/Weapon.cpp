/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:49:44 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/12 08:43:27 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string	weapon) : _type(weapon)
{

}

void	Weapon::setType(std::string newWeaponType)
{
	this->_type = newWeaponType;
}

std::string const Weapon::getType(void)const
{
	return (this->_type);
}

Weapon::~Weapon(void)
{

}

