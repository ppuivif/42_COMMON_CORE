/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:02 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 18:04:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	int		nb_animal = 10;
	
	if (nb_animal % 2)
		return (1);
	
	AAnimal	**meta = new AAnimal*[nb_animal];  // Allocate space for 5 Animal* pointers

	for (int h = 0; h < nb_animal ; h++)
	{
		if (h < nb_animal / 2)
		{
			std::string name = "cat_" + toString(h + 1);
			meta[h] = new Cat(name);
		}
		else
		{
			std::string name = "dog_" + toString(h - nb_animal / 2 + 1);
			meta[h] = new Dog(name);
		}
		std::cout << GREEN;
		meta[h]->makeSound();
		std::cout << NORMAL;
		std::cout << std::endl;
	}

	for (int h = 0; h < nb_animal; h++)
	{
		std::string name = meta[h]->getType();
		delete meta[h];
		std::cout << RED << name << " has been destroyed" << NORMAL << std::endl << std::endl;
	}

	delete [] meta;
	return (0);
}