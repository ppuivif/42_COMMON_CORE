/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:06:34 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/16 18:24:42 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Materia.hpp"

#ifndef ICE_HPP
# define ICE_HPP

class Ice
{
	public:
		Ice(void);
		Ice(const Ice &rhs);
		Ice & operator=(const Ice &rhs);
		~Ice(void);
	
		Ice *clone() const; //clone an instance and create an instance of same type
		void use(ICharacter & target); //display a message
};

#endif