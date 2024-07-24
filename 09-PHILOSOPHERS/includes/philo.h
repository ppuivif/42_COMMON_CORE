/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:30:45 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/24 15:13:14 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data	t_data;
typedef struct s_data
{
	int				philo_nmemb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_number;
	long int		start_time;
	pthread_mutex_t	mutex_for_print;
	pthread_mutex_t	mutex_for_fork;
}	t_data;

typedef struct s_fork	t_fork;
typedef struct s_fork
{
	int				fork_id;
	bool			fork_is_available;
}	t_fork;

typedef struct s_philo	t_philo;
typedef struct s_philo
{
	int				philo_id;
	pthread_t		philo_thread;
	int				meals_count;
	t_fork			*right_fork;		
	t_fork			*left_fork;
	int				number_of_available_forks;
	t_data			*data;
}	t_philo;

/*
* Utils
*/

void	ft_putstr_fd(char *s, int fd);
bool	ft_isspace(int c);
void	*ft_calloc(size_t nmemb, size_t size);

/*
* Parsing
*/

int		check_and_convert_arguments(char **argv, t_data *data);

/*
* Initialization
*/

int		init_forks_struct(t_data data, t_fork **fork);
int		init_philos_struct(t_data data, t_philo **philo, t_fork *fork);

/*
* Free
*/

void    free_all(t_philo *philo, t_fork *fork);


/*
* Tests
*/

void	data_struct_print(t_data data);
void	forks_struct_print(t_fork *fork, t_data data);
void	philos_struct_print(t_philo *philo, t_data data);

#endif