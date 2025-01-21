/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:28 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 16:50:52 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <sstream> //for ostringstream

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const & rhs);
		AAnimal & operator=(AAnimal const & rhs);
		virtual ~AAnimal(void);

		AAnimal(std::string const & type);
		std::string getType(void) const;

		virtual void makeSound(void) const = 0;

	protected:
		std::string	_type;
};

std::string	toString(int nb);

#endif