/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:59:24 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/22 18:36:42 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib> //for rand
#include <ctime>
#include <exception>

class Base
{
	public:
		virtual ~Base();
};

Base	* generate(void);
void	identify(Base * p);
void	identify(Base & p);

#endif
