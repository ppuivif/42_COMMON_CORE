/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:47 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/26 09:04:04 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*horde;
	std::string	zombieName;

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
		std::getline(std::cin, input);
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

	while (input.empty())
	{
		std::cout << BOLD << "Enter \'zombieName\' : " << NORMAL;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		if (input.empty())
			std::cout << RED << "Enter a valid input (non empty) : " << NORMAL << std::endl;
	}
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
