#include "philo.h"

void	data_struct_print(t_data data)
{
	printf("number of philo : %d\n", data.philo_nmemb);
	printf("time to die : %d\n", data.time_to_die);
	printf("time to eat : %d\n", data.time_to_eat);
	printf("time to sleep : %d\n", data.time_to_sleep);
	printf("meals number : %d\n", data.meals_number);
}

void	philos_struct_print (t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	while (i < data.philo_nmemb)
	{
		printf("index philo[%d] : %d\n", i, philo[i].index);
		i++;
	}
}
