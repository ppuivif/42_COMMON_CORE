/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:20:42 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/11 18:16:46 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include "../LIBFT/libft.h"

typedef struct s_element
{
	int					*number;
	int					*position;
	struct s_element	*next;
	struct s_element	*previous;
}	t_element;

typedef struct s_list
{
	int			size;
	t_element	*head;
}	t_list;

t_element	*ft_lst_dc_new(void *content, void *position);
void		ft_lst_dc_add_back(t_element **head, t_element *new_element);
void		ft_lst_dc_add_front(t_element **head, t_element *new_element);
t_element	*ft_lst_dc_last(t_element *head);
size_t		ft_lst_dc_size(t_element *head);
void		ft_lst_dc_print(t_element *head);
void		ft_lst_dc_delone (t_element **head, t_element *element_to_del);

#endif
