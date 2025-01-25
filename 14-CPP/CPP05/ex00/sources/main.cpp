/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/25 15:29:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	run_test1()
{
	std::cout << BOLD << std::endl << "----------- test1 : default construction -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat1;
		std::cout << bureaucrat1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test1, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test2()
{
	std::cout << BOLD << std::endl << "----------- test2 : simple construction with grade initialization at 0 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat2("bureaucrat2", 0);
		std::cout << bureaucrat2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test2, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}	

void	run_test3()
{
	std::cout << BOLD << std::endl << "----------- test3 : simple construction with grade initialization at 151 -----------" << NORMAL << std::endl;
	
	try
	{
		Bureaucrat bureaucrat3("bureaucrat3", 151);
		std::cout << bureaucrat3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test3, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}	

void	run_test4()
{
	std::cout << BOLD << std::endl << "----------- test4 : simple construction with decrease out of range -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat4("bureaucrat4", 150);
		std::cout << bureaucrat4 << std::endl;
		bureaucrat4.increase_grade();
		std::cout << bureaucrat4 << std::endl;
		bureaucrat4.decrease_grade();
		std::cout << bureaucrat4 << std::endl;
		bureaucrat4.decrease_grade();
		std::cout << bureaucrat4 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test4, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test5()
{
	std::cout << BOLD << std::endl << "----------- test5 : simple construction with increase out of range -----------" << NORMAL << std::endl;
	
	try
	{
		Bureaucrat bureaucrat5("bureaucrat5", 1);
		std::cout << bureaucrat5 << std::endl;
		bureaucrat5.decrease_grade();
		std::cout << bureaucrat5 << std::endl;
		bureaucrat5.increase_grade();
		std::cout << bureaucrat5 << std::endl;
		bureaucrat5.increase_grade();
		std::cout << bureaucrat5 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test5, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

int main()
{
	try
	{
		run_test1();
		run_test2();
		run_test3();
		run_test4();
		run_test5();
	}
	catch (std::exception & e)
	{
		return (1);
	}
	return (0);
}