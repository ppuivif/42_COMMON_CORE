/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/27 19:57:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Bureaucrat.hpp"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(Form const & rhs);
		Form & operator=(Form const & rhs);
		~Form();

		Form(std::string name, int signGrade, int execGrade);
    
		std::string const	& getName() const;
		bool 				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void		beSigned(Bureaucrat const & bureaucrat);

		class	GradeTooLowException : public std::exception
		{
			virtual const char	* what() const throw()
			{
				return ("grade is out of range (too low)");
			}
		};
		class	GradeTooHighException : public std::exception
		{
			virtual const char	* what() const throw()
			{
				return ("grade is out of range (too high)");
			}
		};

	private:
		std::string	const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif