/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:50:35 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:31:00 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor Brain called" << std::endl;
}

Brain::Brain(Brain const &rhs)
{
	*this = rhs;
	std::cout << "Copy constructor Brain called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdea(i);
	}
	std::cout << "Assignment operator Brain called" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor Brain called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Index is out of range." << std::endl;
		return (NULL);
	}
	return(this->_ideas[index]);
}

void Brain::setIdea(std::string const & idea)
{
	int	i = 0;
	
	while (i < 100)
	{
		if (this->_ideas[i].empty())
		{
			this->_ideas[i] = idea;
			std::cout << "Idea has been set successfully." << std::endl;
			break;
		}		
		i++;
	}
	if (i >= 100)
		std::cout << "There isn't any place more to set a new idea" << std::endl;
}