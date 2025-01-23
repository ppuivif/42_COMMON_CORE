/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:03:32 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/23 19:24:19 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat bureaucrat1;
	Bureaucrat bureaucrat2("bureaucrat2_name", 2);
	std::cout << "Name of bureaucrat1 is : " << bureaucrat1.getName() << std::endl;
	std::cout << "Grade of bureaucrat1 is : " << bureaucrat1.getGrade() << std::endl;
	std::cout << "Name of bureaucrat2 is : " << bureaucrat2.getName() << std::endl;
	std::cout << "Grade of bureaucrat2 is : " << bureaucrat2.getGrade() << std::endl;
    
}