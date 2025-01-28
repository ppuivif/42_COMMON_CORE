/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/28 18:06:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	run_test1()
{
	std::cout << BOLD << std::endl << "----------- test1 : default construction bureaucrat -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat1;
		std::cout << bureaucrat1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test1, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}

void	run_test2()
{
	std::cout << BOLD << std::endl << "----------- test2 : simple construction bureaucrat with grade initialization at 0 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat2("bureaucrat2", 0);
		std::cout << bureaucrat2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test2, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}	

void	run_test3()
{
	std::cout << BOLD << std::endl << "----------- test3 : simple construction bureaucrat with grade initialization at 151 -----------" << NORMAL << std::endl;
	
	try
	{
		Bureaucrat bureaucrat3("bureaucrat3", 151);
		std::cout << bureaucrat3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test3, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}	

void	run_test4()
{
	std::cout << BOLD << std::endl << "----------- test4 : simple construction bureaucrat with decrease out of range -----------" << NORMAL << std::endl;

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
		throw;
	}
}

void	run_test5()
{
	std::cout << BOLD << std::endl << "----------- test5 : simple construction bureaucrat with increase out of range -----------" << NORMAL << std::endl;
	
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
		throw;
	}
}

void	run_test6()
{
	std::cout << BOLD << std::endl << "----------- test6 : default construction form -----------" << NORMAL << std::endl;

	try
	{
		Form form6;
		std::cout << form6 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test6, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}

void	run_test7()
{
	std::cout << BOLD << std::endl << "----------- test7 : simple construction form with sign grade initializated at 0 -----------" << NORMAL << std::endl;

	try
	{
		Form form7("form7", 0, 1);
		std::cout << form7 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test7, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}	

void	run_test8()
{
	std::cout << BOLD << std::endl << "----------- test8 : simple construction form with execute grade initializated at 151 -----------" << NORMAL << std::endl;

	try
	{
		Form form8("form8", 150, 151);
		std::cout << form8 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test8, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}	

void	run_test9()
{
	std::cout << BOLD << std::endl << "----------- test9 : form beSigned by bureaucrat grade 1 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat9("bureaucrat9", 1);
		std::cout << bureaucrat9 << std::endl;
		Form form9("form9", 20, 50);
		std::cout << form9 << std::endl;
		bureaucrat9.signForm(form9);
		std::cout << form9 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test9, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}

void	run_test10()
{
	std::cout << BOLD << std::endl << "----------- test10 : form beSigned by bureaucrat grade 150 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat10("bureaucrat10", 150);
		std::cout << bureaucrat10 << std::endl;
		Form form10("form10", 20, 50);
		std::cout << form10 << std::endl;
		bureaucrat10.signForm(form10);
		std::cout << form10 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test10, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}

void	run_test11()
{
	std::cout << BOLD << std::endl << "----------- test11 : form already signed beSigned by bureaucrat grade 1 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat bureaucrat11("bureaucrat11", 1);
		std::cout << bureaucrat11 << std::endl;
		Form form11("form11", 20, 50);
		std::cout << form11 << std::endl;
		bureaucrat11.signForm(form11);
		std::cout << form11 << std::endl;
		bureaucrat11.signForm(form11);
		std::cout << form11 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test11, an error occured : " << e.what() << NORMAL << std::endl;
		throw;
	}
}

int main()
{
	try
	{
//		run_test1();
//		run_test2();
//		run_test3();
//		run_test4();
//		run_test5();

//		run_test6();
//		run_test7();
//		run_test8();
//		run_test9();
//		run_test10();
		run_test11();
	}
	catch (std::exception & e)
	{
		return (1);
	}
	return (0);
}