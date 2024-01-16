#include "ft_list.h"

t_list  *ft_lstnew(void *content)
{
    t_list *tmp;

    tmp = malloc(sizeof(t_list));
    if (!tmp)
        return (NULL);
    tmp->content = content;
    tmp->next = NULL;
    return(tmp);
}

#include <stdio.h>

int main()
{
	t_list *element1 = ft_lstnew()

}
