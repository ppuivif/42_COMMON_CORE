/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:50:05 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/21 17:35:02 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIA_HPP
# define MATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria &rhs);
		AMateria & operator=(const AMateria & rhs);
		virtual ~AMateria(void);

		AMateria(const std::string & type);

		const std::string & getType() const; //returns the materia type
		virtual AMateria *clone() const = 0; //clone an instance and create an instance of same type
		void use(std::string target);
//		virtual void use(ICharacter & target); //display a message

	protected:
		std::string	_type;
};

#endif