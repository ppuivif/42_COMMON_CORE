/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:57:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/23 18:35:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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

/*		class	GradeTooLowException
		{
			public:

		};
		
		class	GradeTooHighException
		{
			public:
			
		};*/
		
	private:
		std::string	const _name;
		int			_grade;
};

#endif