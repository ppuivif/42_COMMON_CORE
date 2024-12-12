/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:02 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/12 19:01:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();

//	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
//	std::cout << meta->getType() << " " << std::endl;
	dog->makeSound();

	delete meta;
	delete dog;
	return (0);
}