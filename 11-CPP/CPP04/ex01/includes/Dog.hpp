/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:32:37 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 15:08:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class	Dog : public Animal, public Brain
{
	public:
		Dog(void);
		Dog(const Dog &rhs);
		Dog &operator=(const Dog &rhs);
		~Dog(void);

		Dog(std::string type);
		void makeSound() const;
	
	private:
		Brain *_brain;
};

#endif