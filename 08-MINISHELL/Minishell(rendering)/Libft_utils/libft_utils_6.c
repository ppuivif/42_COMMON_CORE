/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:08:21 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/04 09:26:34 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

void	close_fd(int fd)
{
	if (fd && fd > 2 && fd != STDIN_FILENO && fd != STDOUT_FILENO)
		close(fd);
}

void	*free_and_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

char	**arr_copy(char **arr)
{
	int		i;
	int		nmemb;
	char	**result;

	i = 0;
	nmemb = 0;
	result = NULL;
	while (arr && arr[nmemb])
		nmemb++;
	result = ft_calloc(nmemb + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (arr && arr[i])
	{
		result[i] = ft_strdup(arr[i]);
		i++;
	}
	return (result);
}

void	*free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free (arr[i]);
			arr[i] = NULL;
			i++;
		}
		free (arr);
		arr = NULL;
	}
	return (arr);
}
