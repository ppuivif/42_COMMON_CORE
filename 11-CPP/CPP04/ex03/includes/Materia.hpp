/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:50:05 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 19:04:04 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef MATERIA_HPP
# define MATERIA_HPP

class AMateria
{
	public:
		AMateria(void);
		AMateria(const Materia &rhs);
		AMateria & operator=(const Materia & rhs);
		~Virtual AMateria(void);

		AMateria(std::string const & type);

		std::string const & getType() const; //returns the materia type
		virtual AMateria *clone() const = 0; //clone an instance and create an instance of same type
		virtual void use(ICharacter & target); //display a message

	protected:
		
};

#endif