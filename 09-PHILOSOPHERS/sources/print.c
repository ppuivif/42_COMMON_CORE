/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:37:40 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/26 07:28:05 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *message)
{
	long int	timestamp;

//	if (all_philos_are_alive() == false)
//		return (-1);
	pthread_mutex_lock(&philo->data->mutex_for_print);
	timestamp = get_timestamp_ms(philo->data->start_time);
	printf("%ld ", timestamp);
//	printf("philo %d ", philo->philo_id);
	printf("%d ", philo->philo_id);
	printf("%s\n", message);
	pthread_mutex_unlock(&philo->data->mutex_for_print);
}