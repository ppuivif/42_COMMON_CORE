#include "minishell.h"

int main (void)
{
	int 		i;
	char 		*line;
	t_list		*list;
	t_element	*new_element;
	t_element	*element_to_del;
//	t_element	*parsing_result;

	i = 0;
	list_initialization(&list, 0);
	while (1)
	{
		line = readline("minishell : ");
		if (!line)
			break;
		add_history(line);//here?
	//	parsing_result = ft_parse_command_line(line);
		new_element = ft_lst_dc_new(line, NULL, NULL);
		ft_lst_dc_add_back(&list->head, new_element);
	
		i++;
	}
	ft_lst_dc_print(list->head);
	while (list->head)
	{
		element_to_del = list->head;
		ft_lst_dc_delone(&list->head, element_to_del);
	}
	free(list);
	return (0);
}