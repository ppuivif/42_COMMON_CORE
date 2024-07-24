/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 05:56:56 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/24 10:13:20 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    free_all(t_philo *philo, t_fork *fork)
{
	pthread_mutex_destroy(&philo->data->mutex_for_print);
	if (philo)
	{
		free(philo);
	}
	if (fork)
		free(fork);
}
