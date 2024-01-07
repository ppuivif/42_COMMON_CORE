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
#include <limits.h>

char	*get_next_line(int fd)
{
	int	nb_read_bytes;
//nb_read_bytes est le retour de read, a savoir le nbre d'octets reellement lus
//	size_t	i;
	static char	*buf;
//la variable buf est declaree en statique car elle doit conserver le contenu du debut de la ligne suivante pour l'ecrire (elle est statique jusqu'a le fin de l'execution du prog)
//en statique les variables sont free automatiquement
	char	*tmp;
	char	*line;
//line sera retournee

//	traiter le cas line = NULL ?
//	traiter le cas buf = NULL ?

//	buf[BUFFER_SIZE] = 0;
		
	nb_read_bytes = 0;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
//	if (!buf)
//		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// ne pas mallocer buf, ni remalocer mais plutot remplir de \0
//	if (!line)
/*	line = (char *)malloc(sizeof(char));
	if (!line)
		ft_free_NULL(line);

	else
*/		line = NULL;
//	printf("%s", line);	
	if (buf && ft_find_end_line(buf) > 0)
	{
		line = ft_strjoin(line, ft_close_current_line(buf));
		buf = ft_begin_new_line(buf);
//		printf("%s\n", buf);
		return (line);
	}
	while (1)
	{
		tmp = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!tmp)
			return(NULL);
		nb_read_bytes = read(fd, tmp, BUFFER_SIZE);
//		printf("%d\n", nb_read_bytes);
//		printf("%s", buf);
		tmp[nb_read_bytes] = '\0';
		if (nb_read_bytes == -1)//erreur de lecture
			return(NULL);
		buf = ft_strjoin(buf, tmp);
		if (ft_find_end_line(buf) > 0 || nb_read_bytes == 0)
		{
			line = ft_strjoin(line, ft_close_current_line(buf));
			buf = ft_begin_new_line(buf);
			return (line);
		}
//		line = ft_strjoin(line, buf);
	}
}
