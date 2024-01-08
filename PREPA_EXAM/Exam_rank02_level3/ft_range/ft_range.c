/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:41:01 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/08 11:35:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*int count_digit(int start, int end)
{
    int nbr_digit;

    return (nbr_digit = end - start + 1);
}*/

int *ft_range(int start, int end)
{
    int *tab;
    int i;
    int nbr_digit;
    
    i = 0;
    nbr_digit = abs(end - start);
    tab = malloc((nbr_digit + 1) * sizeof(int));
    if (!tab)
        return (NULL);
    if (end >= start)
    {
        while (start + i <= end)
        {
            tab[i] = start + i;
            i++;
        }
    }
    else
    {
        while (start - i >= end)
        {
            tab[i] = start - i;
            i++;
        }
    }
    return (tab);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc == 3 && (argv[1] <= argv[2]))
    {
        int *tab = ft_range(atoi(argv[1]), atoi(argv[2]));
        while (atoi(argv[1]) + i <= atoi(argv[2]))
        {
            printf("%d\n", tab[i]);
            i++;
        }
    }
    if (argc == 3 && (argv[1] > argv[2]))
    {
        int *tab = ft_range(atoi(argv[1]), atoi(argv[2]));
        while (atoi(argv[1]) - i >= atoi(argv[2]))
        {
            printf("%d\n", tab[i]);
            i++;
        }
    }
    return (0);
}