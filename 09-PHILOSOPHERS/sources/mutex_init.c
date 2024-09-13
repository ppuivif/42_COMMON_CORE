/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:57:37 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/12 10:22:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_mutex_and_data_mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_for_print, NULL))
	{
		ft_putstr_fd("error : a mutex creation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&data->mutex_for_data_access, NULL))
	{
		ft_putstr_fd("error : a mutex creation failed\n", 2);
		pthread_mutex_destroy(&data->mutex_for_print);
		exit(EXIT_FAILURE);
	}
}