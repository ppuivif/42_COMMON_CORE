/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:15:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/27 11:21:30 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);

		std::string		getZombieName(void)const;
		void			announce(void)const;

	private:
		std::string		_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
