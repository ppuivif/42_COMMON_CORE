/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:46:22 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/11 16:57:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main ()
{
	ScavTrap	assailant("ST assailant");
	assailant.guardGate();
	ScavTrap	target1("ST target1");
	target1.guardGate();

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

	std::cout << GREEN << "command : (x110)" << "assailant.attack(\"target2\");" << NORMAL << std::endl;
	for (int i = 0; i < 110; i++)
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

	std::cout << GREEN << "command : " << "target1.takeDamage(110)" << NORMAL << std::endl;
	target1.takeDamage(110);
	target1.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.beRepaired(1);" << NORMAL << std::endl;
	target1.beRepaired(1);
	target1.displayPoints();
	std::cout << std::endl;

	std::cout << GREEN << "command : " << "target1.takeDamage(5)" << NORMAL << std::endl;
	target1.takeDamage(5);
	target1.displayPoints();
	std::cout << std::endl;
}