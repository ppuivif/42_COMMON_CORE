/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:12 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/19 18:14:49 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

	public:
		Fixed(void);
		Fixed(const int	i);
		Fixed(const float f);
		Fixed(const Fixed &src);
		Fixed 	&operator = (const Fixed &src);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_bit = 8;
};

	std::ostream &operator << (std::ostream &out, Fixed const &fx);



#endif