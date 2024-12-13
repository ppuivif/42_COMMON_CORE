/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:51:40 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 17:58:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public AAnimal, public Brain
{
	public:
		Cat(void);
		Cat(const Cat &rhs);
		Cat &operator=(const Cat &rhs);
		~Cat(void);

		Cat(std::string type);
		void makeSound(void) const;
	
	private:
		Brain *_brain;
};

#endif