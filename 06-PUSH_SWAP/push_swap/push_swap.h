/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:49:41 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/30 13:13:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include "FT_PRINTF/libftprintf.h"
# include "GNL/get_next_line.h"
# include <stdlib.h>
# include <limits.h>

void	check_parameters_validity_and_join(char **arg, char **str);
void	check_parameters_are_valid_1(char *arg, char *str);
void	check_parameters_are_valid_2(char *arg, char *str);
int		count_parameters(char **arr);
void	check_parameters_are_integers(char **str_arr);
void	check_no_duplicate(int *int_arr, int count, char **str_arr);
int		check_if_sorted(int *int_arr, int count, char **str_arr);
void	free_tab(char **str_arr);
void	free_arr(char **arr, int *int_arr);
int		ft_atoi_long(char *str);
char	*ft_strjoin_freed(char *s1, char *s2);
int		*build_int_arr(char **str_arr, int count);
void	ft_swap_int(int *a, int *b);
void	ft_sort_int_arr(int *arr, int count);

void	build_and_sort_stacks(char **str_arr, int *int_arr,
			int parameters_number);
int		stack_initialization(t_list	**stack, int size);
void	build_linked_list(int *int_arr, t_list **list);
void	index_stack(t_element **head);
void	update_new_position(t_element **head);
void	free_linked_list(t_list **list);

void	swap(t_element	**head, char c);
void	push(t_element	**head_src, t_element **head_dest, char c);
void	rotate(t_element **head, char c);
void	reverse_rotate(t_element **head, char c);
void	double_swap(t_element **head_a, t_element **head_b);
void	double_rotate(t_element **head_a, t_element **head_b);
void	double_reverse_rotate(t_element **head_a, t_element **head_b);

void	sort_stack_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_2(t_list **src);
void	ft_sort_3(t_list **src, t_list **dest);
void	ft_sort_5(t_list **src, t_list **dest);
void	ft_sort_500(t_list **src, t_list **dest, int chunk);

int		search_new_position_element_with_index(t_list *list, int index);
void	search_best_sort_index(t_list **src, t_list **dest,
			char *char_to_print, int index);
void	ft_butterfly(t_list	**src, t_list **dest, int chunk);
void	ft_sort_back(t_list **src, t_list **dest);
int		optimizing_last_push(t_list **dest, int index_max,
			int index_max_minus_1);

void	build_stacks_for_checker(char **str_arr, int *int_arr,
			int parameters_number);
int		checker(t_list **stack_a, t_list **stack_b);
int		which_instruction(t_list **stack_a, t_list **stack_b, char *tmp);

void	ft_error(t_list **stack_a, t_list **stack_b,
			char **str_arr, int *int_arr);

#endif