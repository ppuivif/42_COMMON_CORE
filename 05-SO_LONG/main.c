/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:22:57 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 16:00:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	*t_win1;

	if (argc == 2)
	{
		check_map_file(argv[1]);
		init_t_window(&t_win1);
		check_map_validity(t_win1, argv[1]);
		main_display(t_win1);
	}
	else
		ft_putstr_fd("Error\nFile .ber missing in order line\n", 1);
	return (0);
}
