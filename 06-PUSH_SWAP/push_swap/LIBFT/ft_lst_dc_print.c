/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_dc_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:39:19 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 13:41:27 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_dc_print(t_element *head)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lst_dc_size(head);
	ft_putstr_fd("number\tinit_position\tnew_position\tnext_position\t \
		index\n", 1);
	while (i < len)
	{
		ft_putnbr_fd(head->number, 1);
		ft_putstr_fd("\t", 1);
		ft_putnbr_fd(head->initial_position, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(head->new_position, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(head->next_position, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(head->index, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
		i++;
	}
	ft_putstr_fd("\n", 1);
}
