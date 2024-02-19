#include <unistd.h>

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char ft_tolower (char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && (str[i] == 32 || str[i] == 9))
		i++;
	while (str && str[i])
	{	
	//	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		if (ft_isalpha(str[i]) != 0)
		{
			if (!str[i + 1] || str[i + 1] == 32 || str[i + 1] == 9)
				str[i] = ft_toupper(str[i]);
			else
				str[i] = ft_tolower(str[i]);
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}