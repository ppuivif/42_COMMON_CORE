/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/01 18:24:19 by ppuivif          ###   ########.fr       */
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
	std::cout << BOLD << std::endl << "----------- test21 : Intern creates ShrubberyCreationForm -----------" << NORMAL << std::endl;

	try
	{
		Intern	intern21;
		AForm	* form21;
		form 21 = intern21.makeForm("ShrubberyCreationForm", "target21");
//		std::cout << *form21 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test21, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

int main()
{
	try
	{
		run_test21();
	//	run_test22();
	//	run_test23();
	//	run_test24();
	//	run_test25();
	}
	catch (std::exception & e)
	{
		return (1);
	}
	return (0);
}