/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:05:50 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/11 16:05:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> // for setw

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#ifndef RED
# define RED "\033[31m"
# endif
#ifndef GREEN
# define GREEN "\033[32m"
# endif
#ifndef BOLD
# define BOLD "\033[1m"
# endif
#ifndef NORMAL
# define NORMAL "\033[0m"
# endif

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		~ClapTrap(void);

		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		void		displayPoints(void) const;
		void		checkHitsAndEnergyPoints(void) const;

	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
