/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:15:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/07 17:57:52 by ppuivif          ###   ########.fr       */
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
	void			*newZombie(std::string name);
	void			randomChump(std::string name);
	void			setZombieName(std::string name);
	std::string		getZombieName(void)const;

private:
	void		_announce(void);
	
	std::string	_name;

};


#endif