/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:37:24 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/28 18:11:22 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default_name"), _grade(150)
{
//	std::cout << "Default constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs._name)
{
	*this = rhs;
//	std::cout << "Copy constructor Bureaucrat called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
//		this->_name = rhs._name; // not possible to set this->_name because it is const
		this->_grade = rhs._grade;
	}
//	std::cout << "Assignment operator Bureaucrat called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
//	std::cout << "Destructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
	{
		std::cout << RED << BOLD << "for " << name << " : initialization grade is out of range" << NORMAL << std::endl;
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		std::cout << RED << BOLD << "for " << name << " : initialization grade is out of range" << NORMAL << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
//	std::cout << "Simple constructor Bureaucrat called" << std::endl;
}

std::string	const	& Bureaucrat::getName(void) const
{
	return(this->_name);
}

int		Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void	Bureaucrat::increase_grade(void)
{
	if (this->_grade > 1)
	{
		this->_grade -= 1;
		std::cout << GREEN << this->_name << " was successfully increased" << NORMAL << std::endl;
	}
	else
	{
		std::cout << RED << BOLD << "for " << this->_name << " : increased grade is out of range" << NORMAL << std::endl;
		throw Bureaucrat::GradeTooHighException();
	}
}

void	Bureaucrat::decrease_grade(void)
{
	if (this->_grade < 150)
	{
		this->_grade += 1;
		std::cout << GREEN << this->_name << " was successfully decreased" << NORMAL << std::endl;
	}
	else
	{
		std::cout << RED << BOLD << "for " << this->_name << " : decreased grade is out of range" << NORMAL << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
}

const char	* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("grade is out of range (too low)");
}

const char	* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("grade is out of range (too high)");
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}
