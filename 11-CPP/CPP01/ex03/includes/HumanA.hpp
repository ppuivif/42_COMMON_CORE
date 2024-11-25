/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:52:01 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/25 12:08:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef	HUMANA_HPP
# define HUMANA_HPP

class   HumanA
{
	public:	
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void		attack(void)const;

	private:
		Weapon		&_weapon;
		std::string	_name;
};

#endif
