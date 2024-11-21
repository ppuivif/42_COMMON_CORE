/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:05:50 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/20 17:20:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		~ClapTrap(void);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string _name;
		int			_hitPoints = 10;
		int			_energyPoints = 10;
		int			_attackDamage = 0;

};

#endif