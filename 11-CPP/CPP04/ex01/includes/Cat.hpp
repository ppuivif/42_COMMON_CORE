/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:51:40 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 08:57:19 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal, public Brain
{
	public:
		Cat(void);
		Cat(Cat const &rhs);
		Cat &operator=(Cat const &rhs);
		~Cat(void);

		Cat(std::string type);
		void makeSound(void) const;
	
	private:
		Brain *_brain;
};

#endif