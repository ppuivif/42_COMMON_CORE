/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:25:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/21 19:29:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int    main()
{
	std::signal(SIGINT, signalHandler);	
	Zombie		*horde = NULL;
	int			N = 0;
	std::string	zombieName;
	
	N = getZombiesNumber();
	if (N == 0)
		std::cout << "No member in horde" << std::endl;
	else
	{
		zombieName = getName();
		horde = zombieHorde(N, zombieName);
		delete [] horde;
		std::cout << "horde has been destroyed" << std::endl;
	}
	return (0);
}
