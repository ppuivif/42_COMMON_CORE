/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:50:05 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:51:27 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

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

		std::string const & getType() const;
		virtual AMateria * clone() const = 0; //clone an instance and create an instance of same type
		virtual void use(ICharacter & target); //display a message

	protected:
		std::string _type;
};

#endif