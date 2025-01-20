/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:06:11 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 18:43:04 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
//	AMateria materiatest2("ice"); // not possible because AMateria is an abstract class and we can't instanciate an object
	Ice icetest;
	Cure curetest;
	Character test("test");

	ICharacter *me = new Character("me_name");
	ICharacter *you = new Character("you_name");
//	*you = *me;

	AMateria *icetest2 = NULL;
	icetest2 = icetest.clone();
	AMateria *curetest2 = NULL;
	curetest2 = curetest.clone();
	
	me->equip(icetest2->clone());
	me->equip(curetest2->clone());
	me->equip(icetest2->clone());
	me->use(1, test);
	me->use(1, *you);
	me->unequip(1);
	me->use(1, test);
	
	IMateriaSource *materiaSource1 = new MateriaSource();
	materiaSource1->learnMateria(icetest2);
	materiaSource1->learnMateria(curetest2);
	me->equip(materiaSource1->createMateria("cure"));
	me->equip(materiaSource1->createMateria("ice"));
	me->use(1, test);
	me->unequip(1);
	me->unequip(0);
	me->equip(materiaSource1->createMateria("cure"));
	me->equip(materiaSource1->createMateria("ice"));
	me->unequip(1);
	me->unequip(0);
	
	delete me;
	delete you;
	delete materiaSource1;
}

