/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:47 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/25 09:50:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	std::cout << (*newZombie).getZombieName() << " has been created" << std::endl;
	newZombie->announce();
	std::cout << std::endl;
	return (newZombie);
}
