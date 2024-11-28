/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:44:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/28 08:17:09 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}
void	Harl::complain(std::string level)
{
	void		(Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levelList[i]))
			(this->*function[i])();
	}
}

void	Harl::debug(void)
{
	std::cout << "Harl debug" <<std::endl;
}

void	Harl::info(void)
{
	std::cout << "Harl info" <<std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Harl warning" <<std::endl;
}

void	Harl::error(void)
{
	std::cout << "Harl error" <<std::endl;
}

Harl::~Harl(void)
{
	return;
}
