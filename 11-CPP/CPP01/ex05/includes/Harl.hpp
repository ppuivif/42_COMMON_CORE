/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:48:44 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/21 11:42:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <csignal> //for signal handling
#include <cstdlib> //for exit

#ifndef HARL_HPP
#define HARL_HPP

#ifndef RED
# define RED "\033[31m"
# endif
#ifndef BOLD
# define BOLD "\033[1m"
# endif
#ifndef NORMAL
# define NORMAL "\033[0m"
# endif

class Harl
{
public:	
	Harl(void);
	~Harl(void);

	void	complain(std::string level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

};

void	signalHandler(int signal);

#endif