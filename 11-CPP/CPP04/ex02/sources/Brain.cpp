/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:50:35 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 17:13:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor Brain called" << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Brain called" << std::endl;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = (rhs.getIdeas())[i];
	}
	std::cout << "Assignment operator Brain called" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor Brain called" << std::endl;
}

const std::string *Brain::getIdeas(void) const
{
	return(this->_ideas);
}
