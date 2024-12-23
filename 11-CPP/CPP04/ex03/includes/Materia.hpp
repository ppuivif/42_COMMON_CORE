/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:50:05 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/23 11:11:12 by ppuivif          ###   ########.fr       */
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
		AMateria(AMateria const & rhs);
		AMateria & operator=(AMateria const & rhs);
		virtual ~AMateria(void);

		AMateria(std::string const & type);

		//const std::string & getType() const; //returns the materia type
		std::string getType() const; //returns the materia type
//		virtual AMateria *clone() const = 0; //clone an instance and create an instance of same type
		void use(std::string target);
//		virtual void use(ICharacter & target); //display a message

	protected:
		std::string _type;
};




#endif