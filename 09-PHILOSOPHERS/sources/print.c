/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:37:40 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/17 18:46:54 by ppuivif          ###   ########.fr       */
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
	if (philo->data->stop_routine == true)
		return (0);//to modify
	pthread_mutex_lock(&philo->data->mutex_for_print);
	printf("%ld %d %s\n", timestamp, philo_id, message);
//	printf("%d ", philo_id);
//	printf("%s\n", message);
	pthread_mutex_unlock(&philo->data->mutex_for_print);
	return (timestamp);
}