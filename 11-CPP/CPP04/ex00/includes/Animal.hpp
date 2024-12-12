/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:04:28 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/12 18:29:13 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &rhs);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal(void);

		Animal(std::string type);
		std::string getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string _type;
};

#endif