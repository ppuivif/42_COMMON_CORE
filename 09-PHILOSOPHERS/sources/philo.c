/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:35:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/26 11:41:52 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*bool	all_philos_reached_meals_number(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < philo->data->philo_nmemb)
	{
		if (philo[i].meals_count == philo->data->meals_number)
			count++;
		i++;
	}
	if (count == philo->data->philo_nmemb)
	{
		printf("all philos reached meals number\n");	
		return (true);
	}
	return (false);
}*/

int	count_available_forks(t_philo *philo)
{
	int	number_of_available_forks;

	number_of_available_forks = 0;
	
//		if (all_philos_are_alive() == false)
//			return (-1);
	

		pthread_mutex_lock(&philo->right_fork->mutex_for_fork);
		if (philo->right_fork->fork_is_available == true)
			number_of_available_forks++;
		pthread_mutex_unlock(&philo->right_fork->mutex_for_fork);

//		if (all_philos_are_alive() == false)
//			return (-1);

		pthread_mutex_lock(&philo->left_fork->mutex_for_fork);
		if (philo->left_fork->fork_is_available == true)
			number_of_available_forks++;
		pthread_mutex_unlock(&philo->left_fork->mutex_for_fork);
	return (number_of_available_forks);	
}

int	take_forks(t_philo *philo)
{
	while (count_available_forks(philo) < 2)
		continue;

	pthread_mutex_lock(&philo->right_fork->mutex_for_fork);
	philo->right_fork->fork_is_available = false;
	print_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->right_fork->mutex_for_fork);

	pthread_mutex_lock(&philo->left_fork->mutex_for_fork);
	philo->left_fork->fork_is_available = false;
	print_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->left_fork->mutex_for_fork);

	return (0);
}

int	take_meal(t_philo *philo)
{
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->right_fork->mutex_for_fork);
	pthread_mutex_lock(&philo->left_fork->mutex_for_fork);
	if (ft_usleep_ms(philo->data->time_to_eat) == -1)
		return (1);
	philo->right_fork->fork_is_available = true;
	philo->left_fork->fork_is_available = true;
	philo->meals_count++;
	pthread_mutex_lock(&philo->data->mutex_for_data_access);
	if (philo->meals_count == philo->data->meals_number)
		philo->data->number_of_satieted_philos++;
	pthread_mutex_unlock(&philo->data->mutex_for_data_access);
	pthread_mutex_unlock(&philo->left_fork->mutex_for_fork);
	pthread_mutex_unlock(&philo->right_fork->mutex_for_fork);
	return (0);
}

int	take_a_rest(t_philo *philo)
{
	print_message(philo, "is sleeping");
	if (ft_usleep_ms(philo->data->time_to_sleep) == -1)
		return (1);
	return (0);
}
bool	check_philos_satieted(t_philo *philo)
{
	bool	return_value;

	return_value = false;
	pthread_mutex_lock(&philo->data->mutex_for_data_access);
	if (philo->data->number_of_satieted_philos == philo->data->philo_nmemb)
		return_value = true;
	pthread_mutex_unlock(&philo->data->mutex_for_data_access);
	return (return_value);
}


void	*routine(t_philo *philo)
{
	print_message(philo, "is thinking");

	if (philo->philo_id % 2 == 0)
		if (ft_usleep_ms(philo->data->time_to_eat) == -1)
		{
			free_all(philo, philo->fork);
			exit (EXIT_FAILURE);
		}
	while (1)
	{

		take_forks(philo);
		if (check_philos_satieted(philo))
			return (NULL);
		if (take_meal(philo) == 1)
		{
			free_all(philo, philo->fork);
			exit (EXIT_FAILURE);
		}
		if (check_philos_satieted(philo))
			return (NULL);
		if (take_a_rest(philo) == 1)
		{
			free_all(philo, philo->fork);
			exit (EXIT_FAILURE);
		}
		if (check_philos_satieted(philo))
			return (NULL);
		print_message(philo, "is thinking");
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
	{
		ft_putstr_fd("error : a mutex creation failed\n", 2);
		return (1);
	}
	if (pthread_mutex_init(&data.mutex_for_data_access, NULL) != 0)
	{
		ft_putstr_fd("error : a mutex creation failed\n", 2);
		return (1);
	}
	if (init_forks_struct(data, &fork) == 1)
	{
		pthread_mutex_destroy(&data.mutex_for_print);
		return (1);
	}
//	forks_struct_print (fork, data);

	data.start_time = get_current_time_ms();
	data.number_of_satieted_philos = 0;
	if (data.start_time == -1)
	{
		free_all(philo, fork);
		return (1);
	}
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
