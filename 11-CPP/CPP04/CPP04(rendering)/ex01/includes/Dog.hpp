/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:32:37 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 08:36:32 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const & rhs);
		Dog &operator=(Dog const & rhs);
		~Dog(void);

		Dog(std::string const & type);
		void makeSound(void) const;
		Brain * getBrain(void) const;
		void setBrain(Brain const & brain);
	
	private:
		Brain *_brain;
};

#endif