/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:37:24 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/23 19:03:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default_name"), _grade(1)
{
	std::cout << "Default constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Bureaucrat called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
//		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	std::cout << "Assignment operator Bureaucrat called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1 || grade > 150)
	{
		std::cout << "error message" << std::endl;
	}
	else
		this->_grade = grade;
	std::cout << "Simple constructor Bureaucrat called" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return(this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void	Bureaucrat::increase_grade(void)
{
	if (this->_grade > 2)
		this->_grade -= 1;
	else
	{
		std::cout << "error increase_grade" << std::endl;
	}
}

void	Bureaucrat::decrease_grade(void)
{
	if (this->_grade < 149)
		this->_grade += 1;
	else
	{
		std::cout << "error decrease_grade" << std::endl;
	}
}
