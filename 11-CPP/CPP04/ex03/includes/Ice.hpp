/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:06:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 17:24:59 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & rhs);
		Ice & operator=(Ice const & rhs);
		~Ice(void);
	
		AMateria	*clone(void) const; //clone an instance and create an instance of same type
		void		use(std::string target); //to delete
		void		use(ICharacter & target); //display a message


};

#endif