/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:52:10 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/11 20:04:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class	Weapon
{
	public:
		Weapon(std::string weapon);
		~Weapon(void);
	
		void 		setType(std::string newWeaponType);
		std::string const getType(void)const;
	
	private:
		std::string	_type;
};

#endif