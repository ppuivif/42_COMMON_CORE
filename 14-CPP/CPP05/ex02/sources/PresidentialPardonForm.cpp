/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:22 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/30 18:11:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
//	std::cout << "Default constructor PresidentialPardonForm called" << std::endl;    
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : AForm(rhs)
{
//	std::cout << "Copy constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm	& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		this->AForm::operator=(rhs);
//	std::cout << "Assignment operator PresidentialPardonForm called" << std::endl;    
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
//	std::cout << "Destructor PresidentialPardonForm called" << std::endl;    
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
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
//	std::cout << "Simple constructor PresidentialPardonForm called" << std::endl;    
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_signed)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}
