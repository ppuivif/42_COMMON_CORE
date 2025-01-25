/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/25 12:02:41 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	run_test1()
{
	std::cout << BOLD << std::endl << "----------- test1 : default construction -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat1;
		std::cout << "Name of bureaucrat1 is : " << bureaucrat1.getName() << std::endl;
		std::cout << "Name of bureaucrat1 is : " << bureaucrat1.getGrade() << std::endl;
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
		Bureaucrat bureaucrat2("bureaucrat2_name", 0);
		std::cout << "Name of bureaucrat2 is : " << bureaucrat2.getName() << std::endl;
		std::cout << "Grade of bureaucrat2 is : " << bureaucrat2.getGrade() << std::endl;
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
		Bureaucrat bureaucrat3("bureaucrat3_name", 151);
		std::cout << "Name of bureaucrat3 is : " << bureaucrat3.getName() << std::endl;
		std::cout << "Grade of bureaucrat3 is : " << bureaucrat3.getGrade() << std::endl;
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
		Bureaucrat bureaucrat4("bureaucrat4_name", 150);
		std::cout << "Grade of bureaucrat4 is : " << bureaucrat4.getGrade() << std::endl;
		std::cout << "Grade of bureaucrat4 is : " << bureaucrat4.getGrade() << std::endl;
		std::cout << "Name of bureaucrat4 is : " << bureaucrat4.getName() << std::endl;
		std::cout << "Grade of bureaucrat4 is : " << bureaucrat4.getGrade() << std::endl << std::endl;
		bureaucrat4.increase_grade();
		std::cout << "New grade of bureaucrat4 is : " << bureaucrat4.getGrade() << std::endl << std::endl;
		bureaucrat4.decrease_grade();
		std::cout << "New Grade of bureaucrat4 is : " << bureaucrat4.getGrade() << std::endl << std::endl;
		bureaucrat4.decrease_grade();
		std::cout << "New Grade of bureaucrat4 is : " << bureaucrat4.getGrade() << std::endl;
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
		Bureaucrat bureaucrat5("bureaucrat5_name", 1);
		std::cout << "Name of bureaucrat5 is : " << bureaucrat5.getName() << std::endl;
		std::cout << "Grade of bureaucrat5 is : " << bureaucrat5.getGrade() << std::endl;
		std::cout << "Name of bureaucrat5 is : " << bureaucrat5.getName() << std::endl;
		std::cout << "Grade of bureaucrat5 is : " << bureaucrat5.getGrade() << std::endl << std::endl;
		bureaucrat5.decrease_grade();
		std::cout << "New grade of bureaucrat5 is : " << bureaucrat5.getGrade() << std::endl << std::endl;
		bureaucrat5.increase_grade();
		std::cout << "New Grade of bureaucrat5 is : " << bureaucrat5.getGrade() << std::endl << std::endl;
		bureaucrat5.increase_grade();
		std::cout << "New Grade of bureaucrat5 is : " << bureaucrat5.getGrade() << std::endl << std::endl;
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