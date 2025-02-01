/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:30:50 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/01 18:10:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
//	std::cout << "Default constructor Intern called" << std::endl;
}

Intern::Intern(Intern const & rhs)
{
	*this = rhs;
//	std::cout << "Copy constructor Intern called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	if (this != &rhs)
		(void)rhs;
	return (*this);
//	std::cout << "Assignement operator Intern called" << std::endl;
}

Intern::~Intern()
{
//	std::cout << "Destructor Intern called" << std::endl;
}

const char * Intern::formDoNotExistException::what() const throw()
{
	return ("Form passed in parameter does no exist");
}

AForm	* Intern::makeForm(std::string const & form, std::string const & target) const
{
	int 	index = 3;
	AForm	*result;
	
	std::string	list[3] = {"PresidentialPardonForm",
							"RobotomyRequestForm",
							"ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (list[i].compare(form))
			index = i;
	}
	switch (index)
	{
		case 0 :
			result = new PresidentialPardonForm(target);
			break;
		case 1 :
			result = new RobotomyRequestForm(target);
			break;
		case 2 :
			result = new ShrubberyCreationForm(target);
			break;
		default :
			throw Intern::formDoNotExistException();
	}
	std::cout << GREEN << BOLD << "Intern creates " << form << NORMAL << std::endl;
	return (result);
}

