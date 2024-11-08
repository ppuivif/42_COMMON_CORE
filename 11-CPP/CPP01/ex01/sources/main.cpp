/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:25:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 15:24:22 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int    main()
{
    Zombie		*horde;
	int			N = 1;
	std::string	zombieName = "Brainy Brian";
	
	if (N == 0)
		std::cout << "No member in horde" << std::endl;
	else if (N < 0)
		std::cout << "Error : invalid number of zombies has been defined" << std::endl;
	else
	{		
		horde = zombieHorde(N, zombieName);
		std::cout << "first zombie is : " << (*horde).getZombieName() << std::endl << std::endl;
		delete [] horde;
		std::cout << "horde has been destroyed" << std::endl;
	}
	return (0);
}