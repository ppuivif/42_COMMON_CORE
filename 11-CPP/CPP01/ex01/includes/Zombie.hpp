/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:15:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/26 09:04:27 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream> //for ostringstream and istringstream to convert toString and toNumber
#include <cstdlib> //for exit
#include <csignal> //for signal handling

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#ifndef RED
# define RED "\033[31m"
# endif
#ifndef BOLD
# define BOLD "\033[1m"
# endif
#ifndef NORMAL
# define NORMAL "\033[0m"
# endif

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void			setZombieName(std::string name);
		std::string		getZombieName(void)const;
		void			announce(void)const;

	private:
		std::string		_name;
};

Zombie		*zombieHorde(int N, std::string name);
int			getZombiesNumber(void);
std::string getName(void);

int			toNumber(std::string str);
std::string	toString(int nb);

#endif
