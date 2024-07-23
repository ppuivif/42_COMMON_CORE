/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:30:45 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/23 13:45:54 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_data	t_data;
typedef struct s_data
{
	int		philo_nmemb;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_number;
}	t_data;

/*typedef struct s_fork t_fork;
typedef struct s_fork
{


}t_fork;*/

typedef struct s_philo	t_philo;
typedef struct s_philo
{
	int		index;
    t_data  *data;
}t_philo;

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

int		init_philos_struct (t_data data, t_philo **philo);


/*
* Tests
*/

void	data_struct_print(t_data data);
void	philos_struct_print (t_philo *philo, t_data data);

#endif