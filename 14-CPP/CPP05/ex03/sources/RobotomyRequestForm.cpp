/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:22 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 19:14:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	std::srand((unsigned) time(NULL));
//	std::cout << "Simple constructor RobotomyRequestForm called" << std::endl;    
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : AForm(rhs)
{
//	std::cout << "Copy constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm	& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
		this->AForm::operator=(rhs);
//	std::cout << "Assignment operator RobotomyRequestForm called" << std::endl;    
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
//	std::cout << "Destructor RobotomyRequestForm called" << std::endl;    
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
	{
		std::cout << RED << BOLD << this->getTarget() << " hasn't been robotomized." << NORMAL << std::endl;
		throw RobotomyRequestForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getExecGrade())
	{
		std::cout << RED << BOLD << this->getTarget() << " hasn't been robotomized." << NORMAL << std::endl;
		throw RobotomyRequestForm::GradeTooLowExceptionToExecute();
	}
	else if (std::rand() % 2)
	{
		std::cout << RED << BOLD << this->getTarget() << " hasn't been robotomized." << NORMAL << std::endl;
	}
	else
	{
		this->makeNoise(this->getTarget());
		std::cout << GREEN << BOLD << this->getTarget() << " has been robotomized." << NORMAL << std::endl;
	}
}

void	RobotomyRequestForm::makeNoise(std::string const & target) const
{
	std::cout << target << " makes some drilling noises" << std::endl;
}
