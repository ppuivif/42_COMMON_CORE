/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:05:50 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/24 17:27:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> // for setw

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

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
		ClapTrap(std::string name);
		
		
		//
		ClapTrap(ClapTrap const &);
		ClapTrap& operator-(ClapTrap const &);
		//


		~ClapTrap(void);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		void		displayPoints(void) const;
		void		checkHitsAndEnergyPoints(void) const;

	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

#endif