/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:15:24 by ppuivif           #+#    #+#             */
/*   Updated: 2023/12/14 20:12:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static char	*eof(char **buf, char **line, char **tmp)
{
	if (*buf)
	{
		if (find_line_return(*buf) > 0)
		{
//			new_function(&(*line), &(*buf));
			*line = close_current_line(*buf);
			*buf = begin_new_line(*buf);
			free(*tmp);
			* tmp = NULL;
			return (*line);
		}
		*line = ft_strjoin(*line, &(*buf));
//		free(*buf);
//		*buf = NULL;
//		free(*line);
		free(*tmp);
		*tmp = NULL;
		return (*line);
	}
	else
	{
		free(*buf);
		*buf = NULL;
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
}

static char	*read_error(char **buf, char **tmp)
{
	free(*buf);
	*buf = NULL;
	free(*tmp);
	*tmp = NULL;
	return (NULL);
}

static char	*get_line(char **buf, char **line)
{
	*line = close_current_line(*buf);
	*buf = begin_new_line(*buf);
	return (*line);
}

/*static void	join_buf(char **buf, char **tmp)
{
	*buf = ft_strjoin(*buf, &(*tmp));
//	free(*tmp);
//	*tmp = NULL;ine = close_current_line(*buf)
}*/

char	*get_next_line(int fd)
{
	int			nb_read_bytes;
	static char	*buf;
	char		*tmp;
	char		*line;

	nb_read_bytes = 0;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		//tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!tmp)
			return(NULL);
		nb_read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (nb_read_bytes == -1)
			return (read_error(&buf, &tmp));
		tmp[nb_read_bytes] = '\0';
		if (nb_read_bytes == 0)
			return (eof(&buf, &line, &tmp));
		buf = ft_strjoin(buf, &tmp);
		if (buf == NULL)
			return (NULL);
		if (find_line_return(buf) > 0)
			return (get_line(&buf, &line));
	}
}

/*int	main(void)
{
	int fd;
	char	*tab;
	int	i = 0;

	fd = open ("document", O_RDWR);
//	if (open = -1) condition a inclure
	
	while (i < 8)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd);
//close permet de fermer l'acces au fichier prealablement open
	return (0);
}*/
