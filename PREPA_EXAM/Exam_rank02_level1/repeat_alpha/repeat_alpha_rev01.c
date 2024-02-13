#include <unistd.h>

void	repeat_alpha(char *str)
{
	int i = 0;
	int j = 0;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			j = 0;
			while (j <= str[i] - 97)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			j = 0;
			while (j <= str[i] - 65)
			{
				write(1, &str[i], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}