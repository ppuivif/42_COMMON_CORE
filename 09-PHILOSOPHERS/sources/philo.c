/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:35:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/24 15:16:24 by ppuivif          ###   ########.fr       */
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

int	ft_usleep(long int duration)
{
	long int		start_time;
	int				i;
//	long int		timestamp;

	i = 0;
	start_time = get_current_time_us();
	if (start_time == -1)
	{
		return (-1);
	}
	while ((get_current_time_us() - start_time) < duration)
		i++;
	return (0);
}


/*int	take_forks(t_philo *philo)
{
	
	
}*/


void	*routine(t_philo *philo)
{
	long int	timestamp;

	timestamp = 0;

	if (philo->philo_id % 2 == 0)
		ft_usleep(50);
	while (1)
	{
		pthread_mutex_lock(&philo->data->mutex_for_fork);
		philo->number_of_available_forks = 0;
		pthread_mutex_unlock(&philo->data->mutex_for_fork);

		pthread_mutex_lock(&philo->data->mutex_for_fork);
		if (philo->right_fork->fork_is_available == true)
			philo->number_of_available_forks++;
		pthread_mutex_unlock(&philo->data->mutex_for_fork);

		pthread_mutex_lock(&philo->data->mutex_for_fork);
		if (philo->left_fork->fork_is_available == true)
			philo->number_of_available_forks++;
		pthread_mutex_unlock(&philo->data->mutex_for_fork);

		if (philo->number_of_available_forks == 2)
		{
			pthread_mutex_lock(&philo->data->mutex_for_print);
			pthread_mutex_lock(&philo->data->mutex_for_fork);
			timestamp = get_timestamp_ms(philo->data->start_time);
			printf("%ld ", timestamp);
			printf("philo %d ", philo->philo_id);
			printf("is eating\n");
			philo->right_fork->fork_is_available = false;
			philo->left_fork->fork_is_available = false;
			ft_usleep(philo->data->time_to_eat / 1000);
//			ft_usleep(1000);
			pthread_mutex_unlock(&philo->data->mutex_for_print);
			pthread_mutex_unlock(&philo->data->mutex_for_fork);
			
			pthread_mutex_lock(&philo->data->mutex_for_print);
			philo->right_fork->fork_is_available = true;
			pthread_mutex_unlock(&philo->data->mutex_for_fork);
			
			pthread_mutex_lock(&philo->data->mutex_for_print);
			philo->left_fork->fork_is_available = true;
			pthread_mutex_unlock(&philo->data->mutex_for_fork);
		}
	}
	return (NULL);
}

int	run_diner(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_nmemb)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, (void *)routine, &philo[i]))
		{
			ft_putstr_fd("error : a thread creation failed\n", 2);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->philo_nmemb)
	{
		if (pthread_join(philo[i].philo_thread, NULL))
		{
			ft_putstr_fd("error : a thread join failed\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	t_fork	*fork;
	struct timeval	time;

	philo = NULL;
	fork = NULL;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error : number of arguments provided \
		is not correct\n", 2);
		return (1);
	}
	if (check_and_convert_arguments(argv, &data) == 1)
		return (1);
//	data_struct_print (data);
	if (pthread_mutex_init(&data.mutex_for_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data.mutex_for_fork, NULL) != 0)
		return (1);
	if (init_forks_struct(data, &fork) == 1)
	{
		pthread_mutex_destroy(&data.mutex_for_print);
		return (1);
	}
//	forks_struct_print (fork, data);

	if (gettimeofday(&time, NULL))
		return (1);
	data.start_time = time.tv_usec;
	if (init_philos_struct(data, &philo, fork) == 1)
	{
		free_all(philo, fork);
		return (1);
	}
//	data_struct_print (*philo->data);
	philos_struct_print (philo, data);
	if (run_diner(&data, philo) == 1)
	{
		free_all(philo, fork);
		return (1);
	}
	free_all(philo, fork);
	return (0);
}
