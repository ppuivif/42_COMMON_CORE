/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:15:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/09 08:39:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	int	nb_read_bytes;
//nb_read_bytes est le retour de read, a savoir le nbre d'octets reellement lus

	static char	*buf;
//la variable buf est declaree en statique car elle doit conserver le contenu du debut de la ligne suivante pour l'ecrire (elle est statique jusqu'a le fin de l'execution du prog)
//en statique les variables sont free automatiquement

	char	*tmp;
	char	*line;
//line sera retournee

//	traiter le cas line = NULL ?
//	traiter le cas buf = NULL ?
		
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
*/
	line = NULL;
//	printf("%s", line);	
/*	if (buf && ft_find_end_line(buf) > 0)
	{
		line = ft_strjoin(line, ft_close_current_line(buf));
		buf = ft_begin_new_line(buf);
//		printf("%s\n", buf);
		return (line);
	}
*/	while (1)
	{
		tmp = calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!tmp)
			return(NULL);
		nb_read_bytes = read(fd, tmp, BUFFER_SIZE);
//		printf("%d\n", nb_read_bytes);
//		printf("%s", buf);
//		tmp[nb_read_bytes] = '\0';
		if (nb_read_bytes <= 0) //erreur de lecture et fin de fichier
		{
			if (nb_read_bytes = 0)
				return (buf);
			free(buf);
			free(tmp);
			return(NULL);
		}
		buf = ft_strjoin(buf, tmp);
		if (buf == NULL)
			return (NULL);
	









		if (find_line_return(buf) > 0)
//|| find_zero(buf) == 1

		{
			line = ft_strjoin(line, close_current_line(buf));
//			printf("%s", buf);
			if (nb_read_bytes < BUFFER_SIZE)
				free(buf);
			else
				buf = begin_new_line(buf);
			return (line);
		}
//		line = ft_strjoin(line, buf);
	}
}

int	main(void)
{
	int fd;
	char	*tab;
	int	i = 0;

	fd = open ("document", O_RDONLY);
	while (i < 2)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		free(tab);
		i++;
	}
	close (fd);
//close permet de fermer l'acces au fichier prealablement open
	return (0);
}


/*int	main(void)
{
	int fd;
	char	*tmp;
	
	tmp=calloc(11, sizeof (char));
	fd = open ("document2", O_RDONLY);
	read(fd, tmp, 10);
	printf("ab%scd", tmp);

}*/
