/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:39:17 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/22 17:21:05 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	std::signal(SIGINT, signalHandler);
	Harl		instance;
	std::string	input;
	std::string	levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			level = 4;

	while (!std::cin.eof())
	{
		std::cout << BOLD << "Chose a level (DEBUG, INFO, WARNING, ERROR) or press CTRL C to interrupt : "<< NORMAL;
		std::getline(std::cin, input);
		for (int i = 0; i < 4; i++)
		{
			if (input == levelList[i])
				level = i;
		}
		if (!std::cin.eof())
		{
			switch (level)
			{
				case 0 :
					instance.complain("DEBUG");
				case 1 :
					instance.complain("INFO");
				case 2 :
					instance.complain("WARNING");
				case 3 :
				{
					instance.complain("ERROR");
					break ;
				}
				default :
					std::cout << RED << "Enter a valid level" << NORMAL << std::endl;
			}
		}
	}
	return (0);
}