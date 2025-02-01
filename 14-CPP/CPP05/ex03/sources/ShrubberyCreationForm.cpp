/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:22 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 19:03:49 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
//	std::cout << "Simple constructor ShrubberyCreationForm called" << std::endl;    
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : AForm(rhs)
{
//	std::cout << "Copy constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm	& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
		this->AForm::operator=(rhs);
//	std::cout << "Assignment operator ShrubberyCreationForm called" << std::endl;    
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
//	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;    
}

const char	* ShrubberyCreationForm::OutfileNotOpenedException::what() const throw()
{
	return ("outfile couldn't be created");
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw ShrubberyCreationForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw ShrubberyCreationForm::GradeTooLowExceptionToExecute();
	else
	{	
		std::string outfile = this->getTarget() + "_shruberry";
		std::ofstream outfileStream;
		outfileStream.open(("./" + outfile).c_str(), std::ifstream::out);
		if (!outfileStream.is_open())
		{
			throw ShrubberyCreationForm::OutfileNotOpenedException();
		}

		outfileStream << "              /\\              /\\            " << std::endl;
		outfileStream << "             /  \\            /  \\           " << std::endl;
		outfileStream << "            /    \\          /    \\          " << std::endl;
		outfileStream << "            /    \\          /    \\          " << std::endl;
		outfileStream << "           /      \\        /      \\         " << std::endl;
		outfileStream << "          /        \\      /        \\        " << std::endl;
		outfileStream << "          /        \\      /        \\        " << std::endl;
		outfileStream << "         /          \\    /          \\       " << std::endl;
		outfileStream << "         ------------    ------------         " << std::endl;
		outfileStream << "              ||              ||              " << std::endl;

		outfileStream.close();

		std::cout << GREEN << BOLD << outfile << " file has been created." << NORMAL << std::endl;
	}
}


