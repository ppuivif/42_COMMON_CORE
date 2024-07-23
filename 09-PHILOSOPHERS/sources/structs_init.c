/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:51:44 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/23 13:46:56 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philos_struct (t_data data, t_philo **philo)
{
	int i;

	i = 0;
	*philo = malloc(data.philo_nmemb * sizeof(t_philo));
	if (!(*philo))
	{
		ft_putstr_fd("error : an allocation failed\n", 2);
		return (1);
	}
	(*philo)->data = &data;
	while (i < data.philo_nmemb)
	{
		(*philo)[i].index = i + 1;
		i++;
	}
	return (0);
}
