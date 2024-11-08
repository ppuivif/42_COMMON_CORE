/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:15:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 12:16:36 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

class Zombie{

public:
	Zombie(void);
	~Zombie(void);

	void			setZombieName(std::string name);
	std::string		getZombieName(void)const;
	void			announce(void)const;

private:
	std::string		_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif