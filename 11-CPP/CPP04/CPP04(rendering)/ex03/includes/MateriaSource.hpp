/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:37:05 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:55:07 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & rhs);
		MateriaSource & operator=(MateriaSource const & rhs);
		~MateriaSource(void);
	
		void 		learnMateria(AMateria * m);
		AMateria	*createMateria(std::string const & type);
	
	private:
		AMateria	*_materia[4];
};

#endif