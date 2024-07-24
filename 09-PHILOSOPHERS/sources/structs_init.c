/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:51:44 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/24 15:17:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks_struct(t_data data, t_fork **fork)
{
	int	i;

	i = 0;
	*fork = malloc(data.philo_nmemb * sizeof(t_fork));
	if (!(*fork))
	{
		ft_putstr_fd("error : an allocation failed\n", 2);
		return (1);
	}
	while (i < data.philo_nmemb)
	{
		(*fork)[i].fork_id = i + 1;
		(*fork)[i].fork_is_available = true;
		i++;
	}
	return (0);
}

int	init_philos_struct(t_data data, t_philo **philo, t_fork *fork)
{
	int	i;

	i = 0;
	*philo = malloc(data.philo_nmemb * sizeof(t_philo));
	if (!(*philo))
	{
		ft_putstr_fd("error : an allocation failed\n", 2);
		return (1);
	}
	while (i < data.philo_nmemb)
	{
		(*philo)[i].data = &data;
		(*philo)[i].philo_id = i + 1;
		(*philo)[i].right_fork = &fork[i];
		if (i != data.philo_nmemb - 1)
			(*philo)[i].left_fork = &fork[i + 1];
		else
			(*philo)[i].left_fork = &fork[0];
		(*philo)[i].number_of_available_forks = 0;
		i++;
	}
	return (0);
}
