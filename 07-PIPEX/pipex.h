/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:43:58 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/18 11:13:43 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

/*typedef enum e_error
{
	NO_RIGHTS = 1,
	NO_FILE = 2,
}	t_err;



void	check_files(char **argv, t_main_struct *main_struct)
{
	main_struct->fd_input = open(argv[1], O_RDONLY);
	if (main_struct->fd_input == -1)
	{
		if (access(argv[1], F_OK) == -1)
		{
			perror(argv[1]);
			main_struct->error_infile = NO_RIGHTS;
		}
		else
		{
			perror(argv[1]);
			main_struct->error_infile = NO_FILE;
		}
	}
	main_struct->fd_output = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (main_struct->fd_output == -1)
	{
		perror(argv[4]);
		main_struct->error_outfile = 1;
	}
}*/

typedef struct s_main_struct
{
	int		fd_input;
	int		fd_output;
	char	**cmd1_arr;
	char	*path1;
	char	**cmd2_arr;
	char	*path2;
}t_main_struct;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin_freed(char *s1, char *s2);
char	*ft_strjoin_freed(char *s1, char *s2);
char	**ft_split(char const *s, char c);

void	check_files(char **argv, t_main_struct *main_struct);
void	build_full_path_cmd_arr(char **argv, char **envp,
			t_main_struct *main_struct);
void	build_cmd_arr(char *argv, char ***cmd_arr, char	**cmd_path, char **envp);
void	check_full_path_in_envp(char ***cmd_arr, char **cmd_path, char **envp, int error_path);
char	**search_path(char **envp);
void	check_path_cmd_validity(char **path, char ***cmd_arr, char **cmd_path,  int error_path);

void	execution(t_main_struct *main_struct, char **envp);
void	exec_child1(t_main_struct *main_struct, int *fd, char **envp);
void	exec_parent(t_main_struct *main_struct, int *fd, char **envp);
void	exec_child2(t_main_struct *main_struct, int *fd, char **envp);

void	init_struct(t_main_struct **main_struct);
void	success_handling(t_main_struct *main_struct);
void	error_handling(t_main_struct *main_struct);
void	free_all(t_main_struct *main_struct);
void	free_arr(char **str_arr);

#endif
