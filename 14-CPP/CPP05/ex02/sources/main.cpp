/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 19:09:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*void	run_test1()
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
	{#include "PresidentialPardonForm.hpp"

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
}*/

void	run_test6()
{
	std::cout << BOLD << std::endl << "----------- test6 : simple construction PresidentialPardonForm -----------" << NORMAL << std::endl;

	try
	{
		PresidentialPardonForm form6("target6");
		std::cout << form6 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test6, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test7()
{
	std::cout << BOLD << std::endl << "----------- test7 : execute PresidentialPardonForm not signed with bureaucrat grade26 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor7("bureaucrat7", 26);
		PresidentialPardonForm form7("target7");
		std::cout << form7 << std::endl;
		executor7.executeForm(form7);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test7, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test8()
{
	std::cout << BOLD << std::endl << "----------- test8 : execute PresidentialPardonForm with bureaucrat grade26 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor8("bureaucrat8", 26);
		PresidentialPardonForm form8("target8");
		std::cout << form8 << std::endl;
		executor8.signForm(form8);
		std::cout << form8 << std::endl;
		executor8.executeForm(form8);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test8, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test9()
{
	std::cout << BOLD << std::endl << "----------- test9 : execute PresidentialPardonForm with bureaucrat grade6 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor9("bureaucrat9", 6);
		PresidentialPardonForm form9("target9");
		std::cout << form9 << std::endl;
		executor9.signForm(form9);
		std::cout << form9 << std::endl;
		executor9.executeForm(form9);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test9, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test10()
{
	std::cout << BOLD << std::endl << "----------- test10 : execute PresidentialPardonForm with bureaucrat grade5 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor10("bureaucrat10", 5);
		PresidentialPardonForm form10("target10");
		std::cout << form10 << std::endl;
		executor10.signForm(form10);
		std::cout << form10 << std::endl;
		executor10.executeForm(form10);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test10, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}
void	run_test11()
{
	std::cout << BOLD << std::endl << "----------- test11 : simple construction RobotomyRequestForm -----------" << NORMAL << std::endl;

	try
	{
		RobotomyRequestForm form11("target11");
		std::cout << form11 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test11, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test12()
{
	std::cout << BOLD << std::endl << "----------- test12 : execute RobotomyRequestForm not signed with bureaucrat grade46 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor12("bureaucrat12", 46);
		RobotomyRequestForm form12("target12");
		std::cout << form12 << std::endl;
		executor12.executeForm(form12);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test12, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test13()
{
	std::cout << BOLD << std::endl << "----------- test13 : execute RobotomyRequestForm with bureaucrat grade73 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor13("bureaucrat13", 73);
		RobotomyRequestForm form13("target13");
		std::cout << form13 << std::endl;
		executor13.signForm(form13);
		std::cout << form13 << std::endl;
		executor13.executeForm(form13);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test13, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test14()
{
	std::cout << BOLD << std::endl << "----------- test14 : execute RobotomyRequestForm with bureaucrat grade46 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor14("bureaucrat14", 46);
		RobotomyRequestForm form14("target14");
		std::cout << form14 << std::endl;
		executor14.signForm(form14);
		std::cout << form14 << std::endl;
		executor14.executeForm(form14);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test14, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test15()
{
	std::cout << BOLD << std::endl << "----------- test15 : execute RobotomyRequestForm with bureaucrat grade45 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor15("bureaucrat15", 45);
		RobotomyRequestForm form15("target15");
		std::cout << form15 << std::endl;
		executor15.signForm(form15);
		std::cout << form15 << std::endl;
		executor15.executeForm(form15);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test15, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test16()
{
	std::cout << BOLD << std::endl << "----------- test16 : simple construction ShrubberyCreationForm -----------" << NORMAL << std::endl;

	try
	{
		ShrubberyCreationForm form16("target16");
		std::cout << form16 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test16, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test17()
{
	std::cout << BOLD << std::endl << "----------- test17 : execute ShrubberyCreationForm not signed with bureaucrat grade146 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor17("bureaucrat17", 146);
		ShrubberyCreationForm form17("target17");
		std::cout << form17 << std::endl;
		executor17.executeForm(form17);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test17, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test18()
{
	std::cout << BOLD << std::endl << "----------- test18 : execute ShrubberyCreationForm with bureaucrat grade145 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor18("bureaucrat18", 145);
		ShrubberyCreationForm form18("target18");
		std::cout << form18 << std::endl;
		executor18.signForm(form18);
		std::cout << form18 << std::endl;
		executor18.executeForm(form18);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test18, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test19()
{
	std::cout << BOLD << std::endl << "----------- test19 : execute ShrubberyCreationForm with bureaucrat grade138 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor19("bureaucrat19", 138);
		ShrubberyCreationForm form19("target19");
		std::cout << form19 << std::endl;
		executor19.signForm(form19);
		std::cout << form19 << std::endl;
		executor19.executeForm(form19);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test19, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
	}
}

void	run_test20()
{
	std::cout << BOLD << std::endl << "----------- test20 : execute ShrubberyCreationForm with bureaucrat grade137 -----------" << NORMAL << std::endl;

	try
	{
		Bureaucrat executor20("bureaucrat20", 137);
		ShrubberyCreationForm form20("target20");
		std::cout << form20 << std::endl;
		executor20.signForm(form20);
		std::cout << form20 << std::endl;
		executor20.executeForm(form20);
	}
	catch (std::exception & e)
	{
		std::cout << RED << BOLD << "In test20, an error occured : " << e.what() << NORMAL << std::endl;
//		throw;
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

/*	std::cout << BOLD << std::endl << "************* TESTS ON PRESIDENTIAL PARDON FORM *************" << NORMAL << std::endl;
		run_test6();
		run_test7();
		run_test8();
		run_test9();
		run_test10();*/

	std::cout << BOLD << std::endl << std::endl << "************* TESTS ON ROBOTOMY REQUEST FORM *************" << NORMAL << std::endl;
//		run_test11();
//		run_test12();
		run_test13();
		run_test14();
		run_test15();

/*	std::cout << BOLD << std::endl << std::endl << "************* TESTS ON SHRUBBERY CREATION FORM *************" << NORMAL << std::endl;
		run_test16();
		run_test17();
		run_test18();
		run_test19();
		run_test20();*/
	}
	catch (std::exception & e)
	{
		return (1);
	}
	return (0);
}