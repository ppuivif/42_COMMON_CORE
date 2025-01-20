/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:59:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 17:23:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual~ICharacter(void) {};

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria * m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter & target) = 0;
};

#endif