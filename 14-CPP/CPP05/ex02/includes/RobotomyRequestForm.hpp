/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/30 17:58:20 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "AForm.hpp"
//#include "Bureaucrat.hpp"

int	count;

# define GREEN "\033[32m"
# define RED "\033[31m"
# define BOLD "\033[1m"
# define NORMAL "\033[0m"

//class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor) const;

};

#endif