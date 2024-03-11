#include "libft.h"

void	ft_lst_dc_print(t_element *head)
{
	int len;
	int	i;

	i = 0;
	len = ft_lst_dc_size(head);	
	while (i < len)
	{
		ft_putnbr_fd(head->number, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
		i++;
	}
	ft_putstr_fd("\n", 1);
}