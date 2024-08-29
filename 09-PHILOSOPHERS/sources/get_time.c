/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:34:26 by ppuivif           #+#    #+#             */
/*   Updated: 2024/08/29 10:41:55 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_current_time_ms()
{
	struct timeval	time;
	long int		current_time;

	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("error : gettimeofday failed\n", 2);
		return (-1);
	}
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

long int	get_timestamp_ms(long int start_time)
{
	long int	current_time;
	long int	timestamp;

	current_time = get_current_time_ms();
	if (current_time == -1)
		return (-1);
	timestamp = (current_time - start_time);
	return (timestamp);
}

int	ft_usleep_ms(long int duration)
{
	long int		start_time;

	start_time = get_current_time_ms();
	if (start_time == -1)
		return (-1);
	while ((get_current_time_ms() - start_time) < duration)
		usleep(500);
	return (0);
}
