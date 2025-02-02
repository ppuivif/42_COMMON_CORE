/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/02 17:52:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	run_test21()
{
	std::cout << BOLD << std::endl << "----------- test21 : Intern creates PresidentialPardonForm and Bureaucrat grade26 try to sign form -----------" << NORMAL << std::endl;

	AForm	* form21 = NULL;
	try
	{
		Bureaucrat executor21("bureaucrat21", 26);
		Intern	intern21;
		form21 = intern21.makeForm("PresidentialPardonForm", "target21");
		std::cout << *form21 << std::endl;
		executor21.signForm(*form21);
		std::cout << *form21 << std::endl;
		executor21.executeForm(*form21);
		delete form21;
	}
	catch (std::exception & e)
	{
		delete form21;
		std::cout << RED << BOLD << "In test21, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test22()
{
	std::cout << BOLD << std::endl << "----------- test22 : Intern creates PresidentialPardonForm and Bureaucrat grade6 try to execute form -----------" << NORMAL << std::endl;

	AForm	* form22 = NULL;
	try
	{
		Bureaucrat executor22("bureaucrat22", 6);
		Intern	intern22;
		form22 = intern22.makeForm("PresidentialPardonForm", "target22");
		std::cout << *form22 << std::endl;
		executor22.signForm(*form22);
		std::cout << *form22 << std::endl;
		executor22.executeForm(*form22);
		delete form22;
	}
	catch (std::exception & e)
	{
		delete form22;
		std::cout << RED << BOLD << "In test22, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test23()
{
	std::cout << BOLD << std::endl << "----------- test23 : Intern creates PresidentialPardonForm and Bureaucrat grade5 execute form -----------" << NORMAL << std::endl;

	AForm	* form23 = NULL;
	try
	{
		Bureaucrat executor23("bureaucrat23", 5);
		Intern	intern23;
		form23 = intern23.makeForm("PresidentialPardonForm", "target23");
		std::cout << *form23 << std::endl;
		executor23.signForm(*form23);
		std::cout << *form23 << std::endl;
		executor23.executeForm(*form23);
		delete form23;
	}
	catch (std::exception & e)
	{
		delete form23;
		std::cout << RED << BOLD << "In test23, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test24()
{
	std::cout << BOLD << std::endl << "----------- test24 : Intern creates RobotomyRequestForm and Bureaucrat grade5 execute form -----------" << NORMAL << std::endl;

	AForm	* form24 = NULL;
	try
	{
		Bureaucrat executor24("bureaucrat24", 5);
		Intern	intern24;
		form24 = intern24.makeForm("RobotomyRequestForm", "target24");
		std::cout << *form24 << std::endl;
		executor24.signForm(*form24);
		std::cout << *form24 << std::endl;
		executor24.executeForm(*form24);
		delete form24;
	}
	catch (std::exception & e)
	{
		delete form24;
		std::cout << RED << BOLD << "In test24, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test25()
{
	std::cout << BOLD << std::endl << "----------- test25 : Intern creates ShrubberyCreationForm and Bureaucrat grade5 execute form -----------" << NORMAL << std::endl;

	AForm	* form25 = NULL;
	try
	{
		Bureaucrat executor25("bureaucrat25", 5);
		Intern	intern25;
		form25 = intern25.makeForm("ShrubberyCreationForm", "target25");
		std::cout << *form25 << std::endl;
		executor25.signForm(*form25);
		std::cout << *form25 << std::endl;
		executor25.executeForm(*form25);
		delete form25;
	}
	catch (std::exception & e)
	{
		delete form25;
		std::cout << RED << BOLD << "In test25, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test26()
{
	std::cout << BOLD << std::endl << "----------- test26 : Intern creates DoNotExistForm and Bureaucrat grade5 execute form -----------" << NORMAL << std::endl;

	AForm	* form26 = NULL;
	try
	{
		Bureaucrat executor26("bureaucrat26", 5);
		Intern	intern26;
		form26 = intern26.makeForm("DoNotExistForm", "target26");
		std::cout << *form26 << std::endl;
		executor26.signForm(*form26);
		std::cout << *form26 << std::endl;
		executor26.executeForm(*form26);
		delete form26;
	}
	catch (std::exception & e)
	{
		delete form26;
		std::cout << RED << BOLD << "In test26, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

int main()
{
	try
	{
		run_test21();
		run_test22();
		run_test23();
		run_test24();
		run_test25();
		run_test26();
	}
	catch (std::exception & e)
	{
		return (1);
	}
	return (0);
}