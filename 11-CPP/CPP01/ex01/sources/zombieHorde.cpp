/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:47 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/21 19:37:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
		zombieName = name + "_" + toString(i + 1);
		horde[i].setZombieName(zombieName);
		horde[i].announce();
		std::cout << std::endl;
	}
	return (horde);
}

int	getZombiesNumber(void)
{
	std::string	input;
	int	zombiesNumber = 0;
	
	while (1)
	{
		std::cout << BOLD << "Enter the number of zombies you want in your horde (N) : " << NORMAL;
		std::cin >> input;
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		zombiesNumber = toNumber(input);
		if (zombiesNumber == -1)
			std::cout << RED << "Enter a valid number of zombies" << NORMAL << std::endl;
		else
			break;
	}
	std::cout << std::endl;
	return (zombiesNumber);
}

std::string getName(void)
{
	std::string	input;
	
	std::cout << BOLD << "Enter \'zombieName\' : " << NORMAL;
	std::cin >> input;
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	std::cout << std::endl;
	return (input);
}

std::string	toString(int nb)
{
	std::ostringstream	oss;

	oss << nb;
	return (oss.str());
}

int	toNumber(std::string str)
{
	int					num;
	std::istringstream	iss(str);

	if (!(iss >> num) || num < 0)
		return (-1);
	else
		return (num);
}

void	signalHandler(int signal)
{
	if (signal == SIGINT)
	{
		std::cerr << std::endl << RED << "Warning : program interrupted by CTRL C" << NORMAL << std::endl;
		exit (EXIT_FAILURE);
	}		
}


