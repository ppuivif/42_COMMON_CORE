/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:43:48 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/29 14:38:00 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
//void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strtrim(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
void	free_all(void *s1, void *s2);
//int		find_line_return(char *s);
//char	*close_current_line(char *s1);
//char	*begin_new_line(char *s1);
//void	free_all(char **s1, char **s2);

#endif
