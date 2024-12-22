/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:06:11 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/22 17:44:08 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
//#include "ICharacter"

int main()
{
	AMateria materiatest2("ice");
	Ice icetest;
	Cure curetest;

//	std::string type = materiatest2.getType();
//	type = "cure";
	//std::cout << "type is : " << type <<std::endl;
	std::string type = "old_type";
	std::cout << "new type is : " << modifyType(type) <<std::endl;
	
	
//	AMateria *materiatest2;
//	materiatest2 = materiatest.clone();
//	materiatest2->use("materia_target");

	/*Ice *icetest2;
	icetest2 = icetest.clone();
	icetest2->use("ice_target");

	Cure *curetest2;
	curetest2 = curetest.clone();
	curetest2->use("cure_target");
	
	delete icetest2;
	delete curetest2;*/
}