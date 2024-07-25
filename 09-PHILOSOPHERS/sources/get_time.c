/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:34:26 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/25 07:37:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_current_time_us()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("error : gettimeofday failed\n", 2);
		return (-1);
	}
	return (time.tv_usec);
}

long int	get_timestamp_ms(long int start_time)
{
	long int	time;
	long int	timestamp;

	time = get_current_time_us();
	if (time == -1)
		return (-1);
	timestamp = (time - start_time) / 1000;
	return (timestamp);
}

int	ft_usleep_ms(long int duration)
{
	long int		start_time;
	int				i;

	i = 0;
	start_time = get_current_time_us();
	if (start_time == -1)
	{
		return (-1);
	}
	while ((get_current_time_us() - start_time) / 1000 < duration)
		i++;
	return (0);
}
