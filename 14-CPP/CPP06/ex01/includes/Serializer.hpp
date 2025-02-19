/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:17:29 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/19 18:43:10 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>

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

		static void			_initStruct(t_Data * ptr);
		
	public:
		static uintptr_t	_serialize(t_Data * ptr);
		static t_Data *		_deserialize(uintptr_t raw);
};




#endif