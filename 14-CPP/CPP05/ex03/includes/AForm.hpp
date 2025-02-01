/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 18:16:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class AForm
{
	public:
		AForm();
		AForm(AForm const & rhs);
		AForm & operator=(AForm const & rhs);
		virtual	~AForm();

		AForm(std::string const & name, int signGrade, int execGrade, std::string const & target);
    
		std::string const	& getName() const;
		bool 				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		std::string const	& getTarget() const;

		void				beSigned(Bureaucrat const & bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

	protected:
		class	GradeTooLowException : public std::exception
		{
			virtual const char	* what() const throw();
		};
		class	GradeTooHighException : public std::exception
		{
			virtual const char	* what() const throw();
		};
		class	AlreadySignedException : public std::exception
		{
			virtual const char	* what() const throw();
		};
		class	GradeTooLowExceptionToSign : public std::exception
		{
			virtual const char	* what() const throw();
		};
		class	GradeTooLowExceptionToExecute : public std::exception
		{
			virtual const char	* what() const throw();
		};
		class	NotSignedException : public std::exception
		{
			virtual const char	* what() const throw();
		};

	private:
		std::string	const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
		std::string			_target;

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif