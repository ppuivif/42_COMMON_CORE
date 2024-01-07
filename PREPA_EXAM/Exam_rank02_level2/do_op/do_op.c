/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:16:36 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/16 16:41:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	do_op(int i1, char op, int i2)
{
	int	result;

	result = 0;
	if (op == '+')
		result = i1 + i2;
	else if (op == '-')
		result = i1 - i2;
	else if (op == '*')
		result = i1 * i2;
	else if (op == '/')
		result = i1 / i2;
	printf("%d\n", result);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_op(atoi(argv[1]), argv[2][0], atoi(argv[3]));
	else
		write(1, "\n", 1);
	return (0);
}
