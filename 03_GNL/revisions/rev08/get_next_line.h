/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:26:04 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/31 10:27:49 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t len);
char	*ft_get_strjoin(char *s1, char *s2);
int		ft_get_strchr(const char *str, int c);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_get_substr(char *str, unsigned int start, size_t len);

#endif
