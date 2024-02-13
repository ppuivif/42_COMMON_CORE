char *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s2)
		return (0);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

/*char *ft_strcpy(char *s1, char *s2)
{
	s1 = s2;
	return (s1);
}*/

#include <stdio.h>

int	main()
{
	char src[] = "source";
	char dest[] = "destination";

	printf("%s", ft_strcpy(dest, src));
	return (0);
}


