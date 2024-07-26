/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 05:56:56 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/26 08:27:07 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    free_all(t_philo *philo, t_fork *fork)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->data->mutex_for_print);
	while (i < philo->data->philo_nmemb)
	{
		pthread_mutex_destroy(&(&fork[i])->mutex_for_fork);
		i++;
	}
	if (philo)
	{
		free(philo);
	}
	if (fork)
		free(fork);
}
