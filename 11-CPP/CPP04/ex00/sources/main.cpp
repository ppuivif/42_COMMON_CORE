/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:02 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 09:03:24 by ppuivif          ###   ########.fr       */
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

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //output the cat sound
	j->makeSound(); //output the dog sound
	h->makeSound(); //output the wrongcat sound
	k->makeSound(); //output the wrongcat sound

	delete meta;
	delete wrong;
	delete j;
	delete i;
	delete h;
	delete k;
	return (0);
}
