/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:43:58 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 19:28:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char			**cmd_arr;
	char			*path;
	struct s_cmd	*next;
	struct s_cmd	*previous;
}t_cmd;

typedef struct s_main_struct
{
	int				nb_arg;
	int				fd_input;
	int				fd_output;
	t_cmd			*head;
	t_cmd			*cursor;
}t_main_struct;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin_freed(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);

t_cmd	*ft_lst_dc_new(char **cmd_arr, char *cmd_path);
void	ft_lst_dc_add_back(t_cmd **head, t_cmd *new_cmd);
t_cmd	*ft_lst_dc_last(t_cmd *head);
size_t	ft_lst_dc_size(t_cmd *head);
void	ft_lst_dc_delone(t_cmd **head, t_cmd *cmd_to_del);
void	ft_lst_dc_print(t_cmd *head);
void	ft_putnbr_fd(int n, int fd);

void	check_files(char **argv, t_main_struct *main_struct);
void	build_full_path_cmd_arr(char **argv, char **envp,
			t_main_struct *main_struct);
void	build_cmd_arr(char *argv, char ***cmd_arr, char	**cmd_path,
			char **envp);
void	check_full_path_in_envp(char ***cmd_arr, char **cmd_path, char **envp);
char	**search_path(char **envp);
void	check_path_cmd_validity(char **path, char ***cmd_arr, char **cmd_path);

void	execution(t_main_struct *main_struct, char **envp);
void	exec_first_child(t_main_struct *main_struct, int *fd, char **envp);
void	exec_parent(t_main_struct *main_struct, int *fd, char **envp);
void	exec_last_child(t_main_struct *main_struct, int *fd, char **envp);

void	init_main_struct(t_main_struct **main_struct);
void	success_handling(t_main_struct *main_struct);
void	error_handling(t_main_struct *main_struct);
void	free_all(t_main_struct *main_struct);
void	free_cmd(t_cmd **cmd);
void	free_arr(char **str_arr);

#endif