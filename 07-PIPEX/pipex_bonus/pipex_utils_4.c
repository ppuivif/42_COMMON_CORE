#include "pipex.h"

t_cmd	*ft_lst_dc_new(char **cmd_arr, char *cmd_path)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	else
	{
		new_cmd->cmd_arr = cmd_arr;
		new_cmd->path = cmd_path;
		new_cmd->next = NULL;
		new_cmd->previous = NULL;
	}
	return (new_cmd);
}

void	ft_lst_dc_add_back(t_cmd **head, t_cmd *new_cmd)
{
	t_cmd	*last_cmd;

	if (!new_cmd || !head)
		return ;
	if (!*head)
	{
		*head = new_cmd;
		return ;
	}
	else
	{
		last_cmd = ft_lst_dc_last(*head);
		new_cmd->next = *head;
		new_cmd->previous = last_cmd;
		last_cmd->next = new_cmd;
		(*head)->previous = new_cmd;
	}
}

t_cmd	*ft_lst_dc_last(t_cmd *head)
{
	t_cmd	*last_cmd;

	if (!head)
		return (NULL);
	if (!head->previous)
		last_cmd = head;
	else
		last_cmd = head->previous;
	return (last_cmd);
}

size_t	ft_lst_dc_size(t_cmd *head)
{
	size_t		len;
	t_cmd	*last_cmd;

	len = 1;
	if (!head)
		return (0);
	last_cmd = ft_lst_dc_last(head);
	if (last_cmd == head)
		return (1);
	while (head != last_cmd)
	{
		head = head->next;
		len++;
	}
	return (len);
}

static int	ft_lst_dc_delone_util(t_cmd **head, t_cmd *cmd_to_del)
{
	int	size;

	size = ft_lst_dc_size(*head);
	if (size == 1)
	{
		*head = NULL;
		free_cmd(&cmd_to_del);
		return (1);
	}
	else if (size == 2)
	{
		*head = (*head)->next ;
		(*head)->next = NULL;
		(*head)->previous = NULL;
		free_cmd(&cmd_to_del);
		return (1);
	}
	*head = cmd_to_del->next;
	return (0);
}

void	ft_lst_dc_delone(t_cmd **head, t_cmd *cmd_to_del)
{
	t_cmd	*cmd_to_search;

	if (!cmd_to_del || !head)
		return ;
	if (*head == cmd_to_del)
	{
		if (ft_lst_dc_delone_util(head, cmd_to_del) == 1)
			return ;
	}
	cmd_to_search = *head;
	while (cmd_to_search->next != cmd_to_del)
		cmd_to_search = cmd_to_search->next;
	cmd_to_search->next = cmd_to_search->next->next;
	cmd_to_search->next->previous = cmd_to_search;
	free_cmd(&cmd_to_del);
}

void	ft_lst_dc_print(t_cmd *head)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lst_dc_size(head);
	ft_putstr_fd("index\tcmd\t\toption1\t\toption2\t\tpath\n", 1);
	while (i < len)
	{
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("\t", 1);
		ft_putstr_fd(head->cmd_arr[0], 1);
		ft_putstr_fd("\t\t", 1);
		ft_putstr_fd(head->cmd_arr[1], 1);
		ft_putstr_fd("\t\t", 1);
		ft_putstr_fd(head->cmd_arr[2], 1);
		ft_putstr_fd("\t\t", 1);
		ft_putstr_fd(head->path, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	write (fd, &c, 1);
}