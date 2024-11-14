/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:39:17 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/14 12:29:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl		instance;
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << BOLD << "Chose a level (DEBUG, INFO, WARNING, ERROR) : "<< NORMAL;
		std::getline(std::cin, input);
		if (!std::cin.eof() && input.compare("DEBUG") && input.compare("INFO") && \
		input.compare("WARNING") && input.compare("ERROR"))
			std::cout << RED << "Enter a valid level" << NORMAL << std::endl;
		else
			instance.complain(input);
	}
	return (0);
}