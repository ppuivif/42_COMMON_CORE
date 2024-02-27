/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:22:57 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 20:30:15 by ppuivif          ###   ########.fr       */
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
	else if (argc < 2)
		ft_putstr_fd("Error\nFile .ber missing in order line\n", 2);
	else if (argc > 2)
		ft_putstr_fd("Error\nThere are too many arguments in order line\n", 2);
	return (0);
}
