/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:46:22 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/11 16:57:36 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main ()
{
	ClapTrap	assailant("CT assailant");
	ClapTrap	target1("CT target1");

	std::cout << GREEN << "command : " << "assailant.displayPoints();" << NORMAL << std::endl;
	assailant.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.displayPoints();" << NORMAL << std::endl;
	target1.displayPoints();
	std::cout << std::endl;
	
	std::cout << GREEN << "command : " << "assailant.attack(\"target2\");" << NORMAL << std::endl;
	assailant.attack("target2");
	assailant.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : (x14)" << "assailant.attack(\"target2\");" << NORMAL << std::endl;
	for (int i = 0; i < 14; i++)
		assailant.attack("target2");
	assailant.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "assailant.beRepaired(1);" << NORMAL << std::endl;
	assailant.beRepaired(1);
	assailant.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.takeDamage(1)" << NORMAL << std::endl;
	target1.takeDamage(1);
	target1.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.beRepaired(1);" << NORMAL << std::endl;
	target1.beRepaired(1);
	target1.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.takeDamage(11)" << NORMAL << std::endl;
	target1.takeDamage(11);
	target1.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.beRepaired(1);" << NORMAL << std::endl;
	target1.beRepaired(1);
	target1.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.takeDamage(1)" << NORMAL << std::endl;
	target1.takeDamage(11);
	target1.displayPoints();
	std::cout << std::endl;
}