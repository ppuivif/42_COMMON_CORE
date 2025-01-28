/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:57:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/28 18:03:52 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Form.hpp"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & rhs);
		Bureaucrat & operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		Bureaucrat(std::string const name, int grade);
		
		std::string	const	& getName(void) const;
		int 		getGrade(void) const;
		void		increase_grade(void);
		void		decrease_grade(void);
		void		signForm(Form & form);
		
	private:
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		
		std::string	const _name;
		int			_grade;
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & rhs);

#endif