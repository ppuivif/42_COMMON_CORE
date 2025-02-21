/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:17:29 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/21 18:51:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h> // for uintptr_t
#include <iomanip> // for setprecision

typedef struct s_Data
{
	char	c;
	int		i;
	float	f;
	double	d;
} t_Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer & rhs);
		Serializer & operator=(Serializer & rhs);
		~Serializer();
		
	public:
		static void			initStruct(t_Data * ptr);
		static void			displayStructContent(t_Data const & data);
		static uintptr_t	serialize(t_Data * ptr);
		static t_Data *		deserialize(uintptr_t raw);
};

#endif