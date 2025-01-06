/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:06:11 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/06 18:49:26 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
//	AMateria materiatest2("ice");
	Ice icetest;
	Cure curetest;
	Character test;
	Character test1("test");
	test = test1;
	ICharacter *me = new Character("me_name");
	ICharacter *you = new Character("you_name");

/*	ICharacter *me = new Character();
	ICharacter *you = new Character();*/
	
//	std::string type = materiatest2.getType();
//	type = "cure";
	//std::cout << "type is : " << type <<std::endl;

	
	
//	AMateria *materiatest2;
//	materiatest2 = materiatest.clone();
//	materiatest2->use("materia_target");

	AMateria *icetest2 = NULL;
	icetest2 = icetest.clone();
	AMateria *curetest2;
	curetest2 = curetest.clone();
	/*std::string ice_type = icetest2->getType();
	std::cout << "icetest's type is : " << ice_type <<std::endl;	
	icetest2->use(*me);*/
	me->equip(icetest2);
	me->equip(curetest2);
	//std::cout << you->getName() << std::endl;
	me->use(1, test);
	
/*	me->equip(icetest2);
	me->equip(icetest2);
	me->equip(icetest2);
	me->equip(icetest2);*/

/*	AMateria *curetest2;
	curetest2 = curetest.clone();
	std::string cure_type = curetest2->getType();
	std::cout << "curetest's type is : " << cure_type <<std::endl;
	curetest2->use(*you);*/
	
	delete me;
	delete you;
	delete icetest2;
	delete curetest2;
}