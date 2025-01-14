/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 05:56:56 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/19 09:10:56 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy_and_free_all(t_data *data, t_fork *fork, t_philo *philo)
{
	all_mutex_destroy(data, fork, data->philo_nmemb);
	if (philo)
		free(philo);
	if (fork)
		free(fork);
}
