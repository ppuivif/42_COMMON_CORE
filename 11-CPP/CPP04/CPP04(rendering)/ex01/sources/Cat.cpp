/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:50:56 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/21 09:23:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	try
	{
		this->_brain = new Brain();
	}
	catch (std::bad_alloc & e)
	{
		std::cout << RED << BOLD << "In default constructor Cat, memory allocation failed : " << e.what() << NORMAL << std::endl;
		throw;
	}
	this->_type = "default cat";
	std::cout << "Default constructor Cat called" << std::endl;
}

Cat::Cat(Cat const &rhs) : Animal()
{
	this->_type = rhs.getType();
	if (this->_brain)
	{
		delete this->_brain;
		this->_brain = NULL;
	}
	if (rhs._brain)
	{
		try
		{
			this->_brain = new Brain(*rhs._brain);
		}
		catch (const std::bad_alloc & e)
		{
			std::cout << RED << BOLD << "In copy constructor Cat, memory allocation failed : " << e.what() << NORMAL << std::endl;
			throw;
		}
	}
	else
	{
		try
		{
			this->_brain = new Brain();
		}
		catch (const std::bad_alloc & e)
		{
			std::cout << RED << BOLD << "In copy constructor Cat, memory allocation failed : " << e.what() << NORMAL << std::endl;
			throw;
		}
	}
	std::cout << "Copy constructor Cat called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if (this->_brain)
		{
			delete this->_brain;
			this->_brain = NULL;
		}
		if (rhs._brain)
		{
			try
			{
				this->_brain = new Brain(*rhs._brain);
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << RED << BOLD << "In assignment operator Cat, memory allocation failed : " << e.what() << NORMAL << std::endl;
				throw;
			}
		}
		else
		{
			try
			{
				this->_brain = new Brain();
			}
			catch (const std::bad_alloc & e)
			{
				std::cout << RED << BOLD << "In assignment operator Cat, memory allocation failed : " << e.what() << NORMAL << std::endl;
				throw;
			}
		}
	}
	std::cout << "Assignment operator Cat called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(std::string const & type) : Animal(type)
{
	try
	{
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc & e)
	{
		std::cout << RED << BOLD << "In simple constructor Cat, memory allocation failed : " << e.what() << NORMAL << std::endl;
		throw;
	}
	std::cout << "Simple constructor Cat called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() << " is meowing" << std::endl;
}

Brain * Cat::getBrain(void) const
{
	return (this->_brain);
}

void Cat::setBrain(Brain const & brain)
{
	*this->_brain = brain;
}
