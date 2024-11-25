/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:43:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/25 09:49:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	newZombie(name);

	std::cout << newZombie.getZombieName() << " has been created" << std::endl;
	newZombie.announce();
	std::cout << std::endl;
}
