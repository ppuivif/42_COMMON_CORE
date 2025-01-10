/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:02 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/10 19:37:56 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	int	nb_animal = 10;
	
	if (nb_animal % 2)
		return (1);
	
	Animal	**meta = new (std::nothrow) Animal*[nb_animal];  // Allocate space for nb_animal Animal* pointers
	if (!meta)
	{
		std::cout << RED << BOLD << "In main, memory allocation failed" << NORMAL << std::endl;
		return (1);
	}

	for (int h = 0; h < nb_animal ; h++)
	{
		if (h < nb_animal / 2)
		{
			std::string name = "cat_" + toString(h + 1);
			try
			{
				meta[h] = new Cat(name);
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << RED << BOLD << "In main, memory allocation failed : " << e.what() << NORMAL << std::endl;
				for (int i = 0 ; i < h ; i++)
					delete meta[i];
				delete [] meta;
				return (1);
			}	
		}
		else
		{
			std::string name = "dog_" + toString(h - nb_animal / 2 + 1);
			try
			{
				meta[h] = new Dog(name);
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << RED << BOLD << "In main, memory allocation failed : " << e.what() << NORMAL << std::endl;
				for (int i = 0 ; i < h ; i++)
					delete meta[i];
				delete [] meta;
				return (1);
			}	
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

	Brain	catBrain;
	Brain	dogBrain;
	
	catBrain.setIdea("want to eat");
	catBrain.setIdea("want to sleep");
	catBrain.setIdea("want to meow");
	
	dogBrain.setIdea("want to eat");
	dogBrain.setIdea("want to sleep");
	dogBrain.setIdea("want to bark");
	
	Cat cat1("black cat");
	Dog	dog1("white dog");
	
	cat1.setBrain(catBrain);
	dog1.setBrain(dogBrain);

	std::cout << GREEN << BOLD << cat1.getType() << " " << cat1.getBrain()->getIdea(0) << NORMAL << std::endl;
	std::cout << GREEN << BOLD << dog1.getType() << " " << dog1.getBrain()->getIdea(2) << NORMAL << std::endl;

	delete [] meta;
	return (0);
}