/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:47 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 15:21:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*horde;
	std::string	zombieName;

/*		zombieHorde = new(std::nothrow) Zombie[5];
		if (!zombieHorde)
			std::cout << "Error : allocation failed" << std::endl;*/
	horde = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombieName = name + "_" + std::to_string(i + 1);
		horde[i].setZombieName(zombieName);
		horde[i].announce();
		std::cout << std::endl;
	}
	return (horde);
}
