/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:46:22 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/22 18:34:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main ()
{
	ClapTrap	assailant("assailant");
	ClapTrap	target("target");
	std::string	targetName = target.getName();

	//std::cout << targetName << std::endl;

	assailant.displayPoints();
	target.displayPoints();
	
	assailant.attack(targetName);

}