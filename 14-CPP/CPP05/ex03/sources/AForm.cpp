/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:22 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 15:50:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _signGrade(20), _execGrade(50)
{
//	std::cout << "Default constructor Form called" << std::endl;    
}

AForm::AForm(AForm const & rhs) : _name(rhs._name), _signed(rhs._signed), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade)
{
//	std::cout << "Copy constructor Form called" << std::endl;
}

AForm	& AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
//	std::cout << "Assignment operator Form called" << std::endl;    
	return (*this);
}

AForm::~AForm(void)
{
//	std::cout << "Destructor Form called" << std::endl;    
}

AForm::AForm(std::string const & name, int signGrade, int execGrade, std::string const & target) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade),
	_target(target)
{
	if (signGrade < 1 || execGrade < 1)
	{
		std::cout << RED << BOLD << "for " << name << " : initialization grade for sign or execute is out of range" << NORMAL << std::endl;
		throw AForm::GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
	{
		std::cout << RED << BOLD << "for " << name << " : initialization grade for sign or execute is out of range" << NORMAL << std::endl;
		throw AForm::GradeTooLowException();
	}
//	std::cout << "Simple constructor Form called" << std::endl;    
}

std::string const	& AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

std::string const & AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_signed)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowExceptionToSign();
	else
		this->_signed = true;
}

const char	* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is out of range (too low)");
} 

const char	* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is out of range (too high)");
} 

const char	* AForm::AlreadySignedException::what() const throw()
{
	return ("form has already been signed");
}

const char	* AForm::GradeTooLowExceptionToSign::what() const throw()
{
	return ("grade is out of range to sign (too low)");
}

const char	* AForm::GradeTooLowExceptionToExecute::what() const throw()
{
	return ("grade is out of range to execute (too low)");
}

const char	* AForm::NotSignedException::what() const throw()
{
	return ("form hasn't been signed");
}

std::ostream & operator<<(std::ostream & os, AForm const & rhs)
{
	os << rhs.getName() << ", status " << rhs.getSigned() << ", minimum grade to sign " << rhs.getSignGrade() << ", minimum grade to execute " << rhs.getExecGrade();
	return (os);
}
