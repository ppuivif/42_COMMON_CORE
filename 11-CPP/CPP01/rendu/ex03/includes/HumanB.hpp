/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:52:01 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/27 11:22:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class   HumanB
{
	public:	
		HumanB(std::string name);
		~HumanB(void);

		void		attack(void)const;
		void		setWeapon(Weapon &weapon);

	private:
		Weapon		*_weapon;
		std::string	_name;
		
};

#endif