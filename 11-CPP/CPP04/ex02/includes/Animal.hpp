/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:28 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 18:04:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream> //for ostringstream

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#ifndef GREEN
# define GREEN "\033[32m"
# endif
#ifndef RED
# define RED "\033[31m"
# endif
#ifndef BOLD
# define BOLD "\033[1m"
# endif
#ifndef NORMAL
# define NORMAL "\033[0m"
# endif

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &rhs);
		AAnimal &operator=(const AAnimal &rhs);
		virtual ~AAnimal(void);

		AAnimal(std::string type);
		std::string getType(void) const;

		virtual void makeSound(void) const = 0;

	protected:
		std::string _type;
};

std::string	toString(int nb);

#endif