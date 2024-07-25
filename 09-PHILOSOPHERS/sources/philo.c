/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:35:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/25 11:49:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	count_available_forks(t_philo *philo)
{
	int	number_of_available_forks;

	number_of_available_forks = 0;
	
//		if (all_philos_are_alive() == false)
//			return (-1);

		pthread_mutex_lock(&philo->data->mutex_for_fork);
		if (philo->right_fork->fork_is_available == true)
			number_of_available_forks++;
		pthread_mutex_unlock(&philo->data->mutex_for_fork);

//		if (all_philos_are_alive() == false)
//			return (-1);

		pthread_mutex_lock(&philo->data->mutex_for_fork);
		if (philo->left_fork->fork_is_available == true)
			number_of_available_forks++;
		pthread_mutex_unlock(&philo->data->mutex_for_fork);
	return (number_of_available_forks);	
}

int	take_forks(t_philo *philo)
{
	while (count_available_forks(philo) < 2)
		continue;

	pthread_mutex_lock(&philo->data->mutex_for_fork);
	philo->right_fork->fork_is_available = false;
	pthread_mutex_unlock(&philo->data->mutex_for_fork);

	print_message(philo, "has taken a fork");

	/*pthread_mutex_lock(&philo->data->mutex_for_print);
	print_fork_statement(philo->fork, *philo->data);
	pthread_mutex_unlock(&philo->data->mutex_for_print);*/

//	philos_struct_print (philo, *philo->data);

	pthread_mutex_lock(&philo->data->mutex_for_fork);
	philo->left_fork->fork_is_available = false;
	pthread_mutex_unlock(&philo->data->mutex_for_fork);
	
	print_message(philo, "has taken a fork");

	return (0);
}

int	take_meal(t_philo *philo)
{
	print_message(philo, "is eating");

	pthread_mutex_lock(&philo->data->mutex_for_fork);
	ft_usleep_ms(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->mutex_for_fork);

	pthread_mutex_lock(&philo->data->mutex_for_fork);
	printf("index right_fork : %d\n", philo->right_fork->fork_id);
	printf("right fork is available : %s\n", philo->right_fork->fork_is_available ? "true" : "false");
	philo->right_fork->fork_is_available = true;
	printf("index right_fork : %d\n", philo->right_fork->fork_id);
	printf("right fork is available : %s\n", philo->right_fork->fork_is_available ? "true" : "false");
	pthread_mutex_unlock(&philo->data->mutex_for_fork);
			
	pthread_mutex_lock(&philo->data->mutex_for_fork);
	printf("index left_fork : %d\n", philo->left_fork->fork_id);
	printf("left fork is available : %s\n", philo->left_fork->fork_is_available ? "true" : "false");
	philo->left_fork->fork_is_available = true;
	printf("index left_fork : %d\n", philo->left_fork->fork_id);
	printf("left fork is available : %s\n", philo->left_fork->fork_is_available ? "true" : "false");
	pthread_mutex_unlock(&philo->data->mutex_for_fork);
	return (0);
}

int	take_a_rest(t_philo *philo)
{
	print_message(philo, "is sleeping");

	pthread_mutex_lock(&philo->data->mutex_for_fork);
	ft_usleep_ms(philo->data->time_to_sleep);
	pthread_mutex_unlock(&philo->data->mutex_for_fork);

	return (0);
}


void	*routine(t_philo *philo)
{
	long int	timestamp;

	timestamp = 0;

	if (philo->philo_id % 2 == 0)
		ft_usleep_ms(50);
	while (1)
	{
//		if (philo->philo_id == 1)
		{
			take_forks(philo);
			take_meal(philo);
			take_a_rest(philo);
			print_message(philo, "is thinking");
		}

		

/*		pthread_mutex_lock(&philo->data->mutex_for_print);
		printf("number available forks %d\n", philo->number_of_available_forks++);
		pthread_mutex_unlock(&philo->data->mutex_for_print);

		pthread_mutex_lock(&philo->data->mutex_for_print);
		pthread_mutex_lock(&philo->data->mutex_for_fork);
		printf("right fork is available : %s\n", philo->right_fork->fork_is_available ? "true" : "false");
		pthread_mutex_unlock(&philo->data->mutex_for_print);
		pthread_mutex_unlock(&philo->data->mutex_for_fork);

		pthread_mutex_lock(&philo->data->mutex_for_print);
		pthread_mutex_lock(&philo->data->mutex_for_fork);
		printf("left fork is available : %s\n", philo->left_fork->fork_is_available ? "true" : "false");
		pthread_mutex_unlock(&philo->data->mutex_for_print);
		pthread_mutex_unlock(&philo->data->mutex_for_fork);*/
		
/*		if (philo->number_of_available_forks == 2)
		{

			printf("%ld ", timestamp);
			printf("philo %d ", philo->philo_id);
			printf("is eating\n");
//			printf("time to eat %d\n", philo->data->time_to_eat);
//			ft_usleep_ms(philo->data->time_to_eat);
			ft_usleep_ms(100);
			pthread_mutex_unlock(&philo->data->mutex_for_print);
//			pthread_mutex_unlock(&philo->data->mutex_for_fork);
			
//			pthread_mutex_lock(&philo->data->mutex_for_fork);
//			philo->right_fork->fork_is_available = true;
//			pthread_mutex_unlock(&philo->data->mutex_for_fork);
			
//			pthread_mutex_lock(&philo->data->mutex_for_fork);
//			philo->left_fork->fork_is_available = true;
//			pthread_mutex_unlock(&philo->data->mutex_for_fork);
		}*/
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
//	philos_struct_print (philo, data);
	if (run_diner(&data, philo) == 1)
	{
		free_all(philo, fork);
		return (1);
	}
	free_all(philo, fork);
	return (0);
}
