/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:50:05 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 17:24:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#ifndef RED
# define RED "\033[31m"
# endif
#ifndef GREEN
# define GREEN "\033[32m"
# endif
#ifndef BOLD
# define BOLD "\033[1m"
# endif
#ifndef NORMAL
# define NORMAL "\033[0m"
# endif

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(AMateria const & rhs);
		AMateria & operator=(AMateria const & rhs);
		virtual ~AMateria(void);

		AMateria(std::string const & type);

		std::string const & getType() const; //returns the materia type
		virtual AMateria * clone() const = 0; //clone an instance and create an instance of same type
		virtual void use(ICharacter & target); //display a message
//		virtual void use(std::string target); //to delete

	protected:
		std::string _type;
};




#endif