/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:28 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 08:57:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &rhs);
		Animal &operator=(Animal const &rhs);
		virtual ~Animal(void);

		Animal(std::string _type);
		std::string getType(void) const;

		virtual void makeSound(void) const;

	protected:
		std::string _type;
};

#endif