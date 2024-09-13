/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:37:40 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/13 16:54:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	print_message(t_philo *philo, int philo_id, long int start_time, \
char *message)
{
	long int	timestamp;

//	if (all_philos_are_alive() == false)
//		return (-1);
	timestamp = get_timestamp_ms(philo, start_time);
	pthread_mutex_lock(&philo->data->mutex_for_print);
	if (check_stop_routine(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->mutex_for_print);
		return (start_time);//to modify
	}	
	printf("%ld ", timestamp);
	printf("%d ", philo_id);
	printf("%s\n", message);
	pthread_mutex_unlock(&philo->data->mutex_for_print);
	return (timestamp);
}