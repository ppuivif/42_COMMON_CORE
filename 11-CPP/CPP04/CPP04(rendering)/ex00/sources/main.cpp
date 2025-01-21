/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:02 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 11:45:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal		*meta = new Animal();
	const WrongAnimal	*wrong = new WrongAnimal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*h = new WrongCat();
	const WrongCat		*k = new WrongCat();

	std::cout << "-----------------------------------" << std::endl; 
	std::cout << "meta type is : " << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "wrong type is : " << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	std::cout << std::endl;
	std::cout << "i type is : " << i->getType() << " " << std::endl;
	std::cout << "j type is : " << j->getType() << " " << std::endl;
	std::cout << "h type is : " << h->getType() << " " << std::endl;
	std::cout << "k type is : " << k->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //output the cat sound
	j->makeSound(); //output the dog sound
	h->makeSound(); //output the wrongcat sound
	k->makeSound(); //output the wrongcat sound
	std::cout << "-----------------------------------" << std::endl; 

	delete meta;
	delete wrong;
	delete j;
	delete i;
	delete h;
	delete k;
	return (0);
}
