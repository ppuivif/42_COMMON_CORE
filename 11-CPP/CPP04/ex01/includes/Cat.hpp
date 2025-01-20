/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:51:40 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 15:15:16 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &rhs);
		Cat &operator=(Cat const &rhs);
		~Cat(void);

		Cat(std::string const & type);
		void makeSound(void) const;
		Brain * getBrain(void) const;
		void setBrain(Brain const & brain);
	
	private:
		Brain *_brain;
};

#endif