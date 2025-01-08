/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:59:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/08 19:54:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#define TRASH_SIZE 100

class Character : public ICharacter
{
	public:
		Character(void);
		Character(Character const & rhs);
		Character & operator=(Character const & rhs);
		~Character(void);

		Character(std::string name);
		std::string const & getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter & target);
		
	private:
		int unequipedMateriaStoring(AMateria *m);

		std::string _name;
		AMateria	*_inventory[4];
		int			_indexInTrash;
		AMateria	*_materiaListForTrash[TRASH_SIZE];
		
};

#endif