/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:06:34 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/23 11:14:14 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>
#include "Materia.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & rhs);
		Cure & operator=(Cure const & rhs);
		~Cure(void);
	
		Cure	*clone(void) const; //clone an instance and create an instance of same type
		void	use(std::string target);
//		void	use(ICharacter & target); //display a message
};

#endif