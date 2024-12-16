/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:50:05 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/16 18:05:40 by ppuivif          ###   ########.fr       */
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
		AMateria(const AMateria &rhs);
		AMateria & operator=(const AMateria & rhs);
		virtual ~AMateria(void);

		AMateria(const std::string & type);

		const std::string & getType() const; //returns the materia type
//		virtual AMateria *clone() const = 0; //clone an instance and create an instance of same type
		AMateria *clone() const; //clone an instance and create an instance of same type
//		virtual void use(ICharacter & target) = 0; //display a message
		void use(std::string target); //display a message

	protected:
		std::string	_type;
};

#endif