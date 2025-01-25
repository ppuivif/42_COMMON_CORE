/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:57:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/25 15:08:43 by ppuivif          ###   ########.fr       */
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

		std::ostream & operator<<(std::ostream & os);

		class	GradeTooLowException
		{
			public:
				
		};
		
		class	GradeTooHighException
		{
			public:
			
		};
		
	private:
		std::string	const _name;
		int			_grade;
};

#endif