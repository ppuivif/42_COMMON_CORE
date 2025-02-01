/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/31 18:15:31 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const & executor) const;

	private:
		class	OutfileNotOpenedException : public std::exception
		{
			virtual const char	* what() const throw();
		};
};

#endif