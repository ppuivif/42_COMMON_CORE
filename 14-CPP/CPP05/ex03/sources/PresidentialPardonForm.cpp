/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:22 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 19:04:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5, target)
{
//	std::cout << "Simple constructor PresidentialPardonForm called" << std::endl;    
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw PresidentialPardonForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw PresidentialPardonForm::GradeTooLowExceptionToExecute();
	else
		std::cout << GREEN << BOLD << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << NORMAL << std::endl;
}


