#include "flood_fill_rev01.h"

void	ft_putstr(char *str)
{
	int i = 0;

	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char **create_new_tab(char **tab, t_point size)
{
	char **new_tab;
	int j = 0;
	int i = 0;

	new_tab = malloc(sizeof(char *) * (size.y + 1));
	if(!new_tab)
		return (NULL);
	while (j < size.y)
	{
		i = 0;
		new_tab[j] = malloc(sizeof(char) * (size.x + 1));
		if (!new_tab[j])
			return (NULL);
		while(i < size.x)
		{
			new_tab[j][i] = tab[j][i];
			i++;
		}
		new_tab[j][i] = 0;
		j++;
	}
	new_tab[j] = 0;
	return (new_tab);
}

void	ft_flood_fill(char **tab, t_point size, t_point begin)
{
	int x = begin.x - 1;
	int y = begin.y - 1;
	char c = '0';

	if(y < 0 || x < 0 || y >= size.y || x >= size.x || tab[y][x] != '0')
		return;
	tab[y][x] = 'F';
	if ((x < size.x - 1) && (tab[y][x + 1] == c))
		ft_flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	if ((y < size.y - 1) && (tab[y + 1][x] == c))
		ft_flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	if ((x > 0) && (tab[y][x - 1] == c))
		ft_flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	if ((y > 0) && (tab[y - 1][x] == c))
		ft_flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
}

int main(void)
{
	t_point	size;
	size.x = 8;
	size.y = 5; 
	int i = 0;
	
	t_point	begin;
	begin.x = 1;
	begin.y = 1;

	char	*tab[] = {
		"11111111",
		"10001001",
		"10010101",
		"10110001",
		"11100001",
		};

	while (i < 5)
	{
		ft_putstr(tab[i]);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);

	char **new_tab = create_new_tab(tab, size);
	ft_flood_fill(new_tab, size, begin);

	i = 0;
	while (i < 5)
	{
		ft_putstr(new_tab[i]);
		write(1, "\n", 1);
		i++;
	}
}