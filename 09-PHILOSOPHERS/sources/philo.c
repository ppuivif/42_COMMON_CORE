/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:35:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/13 16:56:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	get_time_before_death_and_sleep(t_philo *philo, long int duration)
{
	long int	remaining_duration_before_death;
	long int	current_time;

	current_time = get_current_time_ms(philo->data, philo->fork, philo);
	
	remaining_duration_before_death = current_time - \
	philo->beginning_of_last_meal;
	
	if (remaining_duration_before_death < philo->data->time_to_die)
	{
		duration = remaining_duration_before_death;
		ft_usleep_ms(philo, duration);
		pthread_mutex_lock(&(philo)->mutex_for_philo);
		philo->is_dead = true;
		pthread_mutex_unlock(&(philo)->mutex_for_philo);		
	}
	ft_usleep_ms(philo, duration);
}


static int	count_available_forks(t_philo *philo)
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

static int	take_forks(t_philo *philo, int philo_id, long int start_time)
{
	while (count_available_forks(philo) < 2)
	{
//		ft_usleep_ms(philo, 100);
		continue;
	}
	pthread_mutex_lock(&philo->right_fork->mutex_for_fork);
	philo->right_fork->fork_is_available = false;
	print_message(philo, philo_id, start_time, "has taken a fork");
	pthread_mutex_unlock(&philo->right_fork->mutex_for_fork);

	pthread_mutex_lock(&philo->left_fork->mutex_for_fork);
	philo->left_fork->fork_is_available = false;
	print_message(philo, philo_id, start_time, "has taken a fork");
	pthread_mutex_unlock(&philo->left_fork->mutex_for_fork);

	return (0);
}

static void	take_meal(t_philo *philo, int philo_id, long int start_time)
{
	philo->beginning_of_last_meal = print_message(philo, philo_id, \
	start_time, "is eating");
	
	get_time_before_death_and_sleep(philo, philo->data->time_to_eat);

	pthread_mutex_lock(&(philo)->mutex_for_philo);
	philo->meals_count++;
	pthread_mutex_unlock(&(philo)->mutex_for_philo);
	
	get_time_before_death_and_sleep(philo, philo->data->time_to_eat);

	pthread_mutex_lock(&philo->right_fork->mutex_for_fork);
	philo->right_fork->fork_is_available = true;
	pthread_mutex_unlock(&philo->right_fork->mutex_for_fork);

	get_time_before_death_and_sleep(philo, philo->data->time_to_eat);

	pthread_mutex_lock(&philo->left_fork->mutex_for_fork);
	philo->left_fork->fork_is_available = true;
	pthread_mutex_unlock(&philo->left_fork->mutex_for_fork);



//	pthread_mutex_lock(&philo->data->mutex_for_data_access);

//	if (philo->meals_count == philo->data->meals_number)
//		philo->data->number_of_satieted_philos++;

//	pthread_mutex_unlock(&philo->data->mutex_for_data_access);
}

static void	take_a_rest(t_philo *philo, int philo_id, long int start_time)
{
	print_message(philo, philo_id, start_time, "is sleeping");
	ft_usleep_ms(philo, philo->data->time_to_sleep);
}

static bool	check_philos_satieted(t_philo *philo, int philo_nmemb, \
int meals_number_for_satieted)
{
	int		i;
	int		number_of_satieted_philos;
	int		meals_count;

	i = 0;
	number_of_satieted_philos = 0;
	meals_count = 0;
	
	while (i < philo_nmemb)
	{
		pthread_mutex_lock(&(&philo[i])->mutex_for_philo);
		meals_count = (&philo[i])->meals_count;
		pthread_mutex_unlock(&(&philo[i])->mutex_for_philo);

		if (meals_count >= meals_number_for_satieted)
			number_of_satieted_philos += 1;
		i++;
	}
	
	if (number_of_satieted_philos == philo_nmemb)
		return (true);
	return (false);
}


static bool	check_if_one_philo_dead(t_philo *philo, long int start_time)
{
	int	i;
	int	index_philo_dead;
	
	i = 0;
	index_philo_dead = 0;
	while (i < philo->data->philo_nmemb)
	{
		pthread_mutex_lock(&(&philo[i])->mutex_for_philo);
		if ((&philo[i])->is_dead == true)
			index_philo_dead = i + 1;
		pthread_mutex_unlock(&(&philo[i])->mutex_for_philo);
		if (index_philo_dead > 0)
		{
			print_message(&philo[i], index_philo_dead, start_time, "is dead");
			return (true);
		}
		i++;
	}
	return (false);
}

void	supervisor(t_philo *philo, int philo_nmemb, long int start_time)
{
	int	i;
	int meals_number_for_satieted;
	
	pthread_mutex_lock(&philo->data->mutex_for_data_access);
	meals_number_for_satieted = philo->data->meals_number;
	pthread_mutex_unlock(&philo->data->mutex_for_data_access);
	while (1)
	{
		i = 0;
		if ((meals_number_for_satieted && check_philos_satieted(philo, \
		philo_nmemb, meals_number_for_satieted) == true) || \
		check_if_one_philo_dead(philo, start_time) == true)
		{
			while (i < philo_nmemb)
			{
				pthread_mutex_lock(&(&philo[i])->mutex_for_philo);
				(&philo[i])->stop_routine = true;
				pthread_mutex_unlock(&(&philo[i])->mutex_for_philo);
				i++;
			}
			return ;
		}
	}
}

bool	check_stop_routine(t_philo *philo)
{
	bool	stop_routine;
	
	stop_routine = false;
	
	pthread_mutex_lock(&philo->mutex_for_philo);
	if (philo->stop_routine == true)
		stop_routine = true;
	pthread_mutex_unlock(&philo->mutex_for_philo);
	
	return (stop_routine);
}

static void	*routine(t_philo *philo)
{
	int			philo_id;
	long int	start_time;

	pthread_mutex_lock(&philo->mutex_for_philo);
	philo_id = philo->philo_id;
	pthread_mutex_unlock(&philo->mutex_for_philo);
	pthread_mutex_lock(&philo->data->mutex_for_data_access);
	start_time = philo->data->start_time;
	pthread_mutex_unlock(&philo->data->mutex_for_data_access);
	if (philo_id % 2 == 0)
		ft_usleep_ms(philo, philo->data->time_to_eat);
	while (check_stop_routine(philo) == false)
	{
		if (check_stop_routine(philo) == false)
			take_forks(philo, philo_id, start_time);
		if (check_stop_routine(philo) == false)
			take_meal(philo, philo_id, start_time);
		if (check_stop_routine(philo) == false)
			take_a_rest(philo, philo_id, start_time);
		if (check_stop_routine(philo) == false)
			print_message(philo, philo_id, start_time, "is thinking");
	}
	return (NULL);
}



static void	run_diner(t_data *data, t_fork *fork, t_philo *philo)
{
	int			i;
	int			philo_nmemb;
	long int	start_time;

	i = 0;
	philo_nmemb = data->philo_nmemb;
	start_time = data->start_time;
	
	while (i < philo_nmemb)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, (void *)routine, &philo[i]))
			error_philo_thread_creation(data, fork, philo, i);
		i++;
	}
	
	supervisor(philo, philo_nmemb, start_time);
	
	i = 0;
	while (i < philo_nmemb)
	{
		if (pthread_join(philo[i].philo_thread, NULL))
			error_philo_thread_join(data, fork, philo);
		i++;
	}
}



int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;
	t_fork	*fork;

	philo = NULL;
	fork = NULL;

	check_arguments_and_fill_data_struct(argc, argv, &data);

//	data_struct_print (data);

	print_mutex_and_data_mutex_init(&data);
	
	forks_struct_init(&data, &fork);

//	forks_struct_print (fork, data);

	data.start_time = get_current_time_ms(&data, fork, NULL);
	
	data.number_of_satieted_philos = 0;
	
	philos_struct_init(&data, fork, &philo);

//	data_struct_print (*philo->data);

//	philos_struct_print (philo, data);

	run_diner(&data, fork, philo);

	mutex_destroy_and_free_all(philo->data, philo->fork, philo);

	return (0);
}
