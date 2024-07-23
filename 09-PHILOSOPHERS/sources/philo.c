/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:35:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/07/23 13:51:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error : number of arguments provided \
		is not correct\n", 2);
		return (1);
	}
	if (check_and_convert_arguments(argv, &data) == 1)
		return (1);
//	data_struct_print (data);
	if (init_philos_struct (data, &philo) == 1)
		return (1);
	data_struct_print (*philo->data);
	philos_struct_print (philo, data);
	return (0);
}
