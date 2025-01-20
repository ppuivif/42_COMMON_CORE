/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:41:53 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/20 11:05:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	try
	{
		this->_brain = new Brain();
	}
	catch (std::bad_alloc & e)
	{
		std::cout << RED << BOLD << "In default constructor Dog, memory allocation failed : " << e.what() << NORMAL << std::endl;
		throw;
	}
	this->_type = "default dog";
	std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(Dog const &rhs) : Animal()
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
			std::cout << RED << BOLD << "In copy constructor Dog, memory allocation failed : " << e.what() << NORMAL << std::endl;
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
			std::cout << RED << BOLD << "In copy constructor Dog, memory allocation failed : " << e.what() << NORMAL << std::endl;
			throw;
		}
	}
	std::cout << "Copy constructor Dog called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
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
				std::cout << RED << BOLD << "In assignment operator Dog, memory allocation failed : " << e.what() << NORMAL << std::endl;
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
				std::cout << RED << BOLD << "In assignment operator Dog, memory allocation failed : " << e.what() << NORMAL << std::endl;
				throw;
			}
		}
	}
	std::cout << "Assignment operator Dog called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	try
	{
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc & e)
	{
		std::cout << RED << BOLD << "In simple constructor Dog, memory allocation failed : " << e.what() << NORMAL << std::endl;
		throw;
	}
	std::cout << "Simple constructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() << " is barking" << std::endl;
}

Brain * Dog::getBrain(void) const
{
	return (this->_brain);
}

void Dog::setBrain(Brain const brain)
{
	*this->_brain = brain;
}