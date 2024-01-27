/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:12:43 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/27 11:08:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ft_lstnew(int content)
{
    t_list  *tmp;

    tmp = malloc(sizeof(t_list));
    if (!tmp)
        return (NULL);
    tmp->content = content;
    tmp->next = NULL;
    return (tmp);
}
