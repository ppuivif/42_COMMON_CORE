#include "flood_fill.h"
#include <stddef.h>
#include <stdlib.h>

char **create_new_tab(char **tab, t_point size)
{
	int i = 0;
	int j = 0;
	char **new_tab;

	new_tab = malloc((size.y + 1) * sizeof(char *));
	if (!new_tab)
		return(NULL);
	while(j < size.y)
	{
		new_tab[j] = malloc((size.x + 1) * sizeof(char));
		if (!new_tab[j])
			return(NULL);
		while(i < size.x && tab[j][i])
		{
			new_tab[j][i] = tab[j][i];
			i++;
		}
		new_tab[j][i + 1] = 0;
		j++;
		i = 0;
	}
	new_tab[size.y + 1] = 0;
	return (new_tab);
}


void	flood_fill(char **tab, t_point size, t_point begin)
{
	int x = begin.x - 1;	
	int y = begin.y - 1;	

	if (y < 0 || y >= size.y || x < 0 || x >= size.x)
		return;
	tab[y][x] = '1';
	if (y > 0)
	{
		if (tab[y - 1][x] == '0' || tab[y - 1][x] == 'C' || tab[y - 1][x] == 'E')
			flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	}
	if (y < size.y - 1)
	{	
		if (tab[y + 1][x] == '0' || tab[y + 1][x] == 'C' || tab[y + 1][x] == 'E')
			flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	}
	if (x > 0)
	{
		if(tab[y][x - 1] == '0' || tab[y][x - 1] == 'C' || tab[y][x - 1] == 'E')
			flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	}
	if (x < size.x - 1)
	{
		if(tab[y][x + 1] == '0' || tab[y][x + 1] == 'C' || tab[y][x + 1] == 'E')
			flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	}
}

#include <stdio.h>

void	print_tab(char **tab, t_point size)
{
	int i = 0;
	int j = 0;

	while(j < size.y)
	{
		while(i < size.x)
		{
			printf("%c", tab[j][i]);
			i++;
		}
		printf("\n");
		j++;
		i = 0;
	}
}

int	main()
{
	char *tab[] = {
		"101100",
		"010000",
		"101110",
		"000101",
	};


	t_point size;
	size.x = 6;
	size.y = 4;

	t_point begin;
	begin.x = 2;
	begin.y = 1;

	print_tab(tab, size);
	printf("\n");
	char **new_tab = create_new_tab(tab, size);
	flood_fill(new_tab, size, begin);
	print_tab(new_tab, size);
}