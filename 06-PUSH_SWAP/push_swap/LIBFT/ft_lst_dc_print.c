#include "libft.h"

void	ft_lst_dc_print(t_element *head)
{
	int len;
	int	i;

	i = 0;
	len = ft_lst_dc_size(head);	
	ft_putstr_fd("number\tinit_position\tnew_position\tnext_position\tindex\n", 1);
	while (i < len)
	{
		ft_putnbr_fd(head->number, 1);
		ft_putstr_fd("\t", 1);
		ft_putnbr_fd(head->initial_position, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(head->new_position, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(head->next_position, 1);
		ft_putstr_fd("\t\t", 1);
		ft_putnbr_fd(head->index, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
		i++;
	}
	ft_putstr_fd("\n", 1);
}