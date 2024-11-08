/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:47 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 11:57:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new Zombie;
	(*newZombie).setZombieName(name);
	std::cout << name << " has been created" << std::endl;
	newZombie->announce();
	std::cout << std::endl;
	return (newZombie);
}
