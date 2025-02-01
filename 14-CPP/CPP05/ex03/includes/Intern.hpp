/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:24:56 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/01 18:02:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class	Intern
{
	public:
		Intern();
		Intern(Intern const & rhs);
		Intern & operator=(Intern const & rhs);
		~Intern();
	
		AForm	* makeForm(std::string const & form, std::string const & target) const;
	
	private:
		class	formDoNotExistException : public std::exception
		{
			virtual const char	* what() const throw();
		};
};

#endif