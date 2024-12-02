/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:12 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/02 09:58:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed 	&operator = (const Fixed &src);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_bit = 8;
};


#endif