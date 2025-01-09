/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:34:02 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 19:03:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	int	nb_animal = 10;
	
	if (nb_animal % 2)
		return (1);
	
	Animal	**meta = new (std::nothrow) Animal*[nb_animal];  // Allocate space for nb_animal Animal* pointers
	if (!meta)
	{
		std::cout << RED << BOLD << "Memory allocation failed" << NORMAL << std::endl;
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
			meta[h] = new Dog(name);
			if (!meta[h])
			{
				std::cout << RED << BOLD << "Memory allocation failed" << NORMAL << std::endl;
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

	delete [] meta;
	return (0);
}