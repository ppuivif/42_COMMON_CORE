/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:57:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/26 19:45:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & rhs);
		Bureaucrat & operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		Bureaucrat(std::string const name, int grade);
		
		std::string	getName(void) const;
		int 		getGrade(void) const;
		void		increase_grade(void);
		void		decrease_grade(void);

		class	GradeTooLowException : public std::exception
		{
			public:
			/*	GradeTooLowException(void);
				virtual ~GradeTooLowException(void);*/
				virtual const char * what() const throw()
				{
//					std::cout << RED << BOLD << "error decrease_grade" << NORMAL << std::endl;
					return("error decrease_grade");
				}
		};
		
		class	GradeTooHighException : public std::exception
		{
			public:
				/*GradeTooHighException(void);
				virtual ~GradeTooHighException(void);*/
				virtual const char * what() const throw()
				{
//					std::cout << RED << BOLD << "error increase_grade" << NORMAL << std::endl;
					return("error increase_grade");
				}
		};
		
	private:
		std::string	const _name;
		int			_grade;
};

	std::ostream & operator<<(std::ostream & os, Bureaucrat & rhs);

#endif