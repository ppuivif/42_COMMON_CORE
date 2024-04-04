/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:18 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/08 11:50:01 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_pointer(unsigned long n);
int	ft_putnbr_base(int nb, int base);
int	ft_putnbr_dec(unsigned int nb);
int	ft_hexa_lower(unsigned int n);
int	ft_hexa_upper(unsigned int n);

#endif
