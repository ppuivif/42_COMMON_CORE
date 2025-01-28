/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:22 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/28 17:48:12 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _signGrade(20), _execGrade(50)
{
//	std::cout << "Default constructor Form called" << std::endl;    
}

Form::Form(Form const & rhs) : _name(rhs._name), _signed(rhs._signed), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade)
{
//	std::cout << "Copy constructor Form called" << std::endl;
}

Form	& Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
//	std::cout << "Assignment operator Form called" << std::endl;    
	return (*this);
}

Form::~Form(void)
{
//	std::cout << "Destructor Form called" << std::endl;    
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
	{
		std::cout << RED << BOLD << "for " << name << " : initialization grade for sign or execute is out of range" << NORMAL << std::endl;
		throw Form::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		std::cout << RED << BOLD << "for " << name << " : initialization grade for sign or execute is out of range" << NORMAL << std::endl;
		throw Form::GradeTooLowException();
	}
//	std::cout << "Simple constructor Form called" << std::endl;    
}

std::string const	& Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_signed)
		throw Form::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char	* Form::GradeTooLowException::what() const throw()
{
	return ("grade is out of range (too low)");
} 

const char	* Form::GradeTooHighException::what() const throw()
{
	return ("grade is out of range (too high)");
} 

const char	* Form::AlreadySignedException::what() const throw()
{
	return ("form has already been signed");
}

std::ostream & operator<<(std::ostream & os, Form const & rhs)
{
	os << rhs.getName() << ", status " << rhs.getSigned() << ", minimum grade to sign " << rhs.getSignGrade() << ", minimum grade to execute " << rhs.getExecGrade();
	return (os);
}
