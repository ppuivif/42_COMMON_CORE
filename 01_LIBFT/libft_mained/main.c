#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
/* test de la fonction ft_strlen */
	if (argc > 0)
	{
		printf("strlen return :\t\t%ld\n", strlen(argv[1]));
		printf("ft_strlen return :\t%ld\n", ft_strlen(argv[1]));
	}
			

/* test de la fonction ft_split */
/*	if (argc > 0)
	{	int	i = 0;
		char	**tab = ft_split(argv[1], argv[2][0]);
		printf("ft_split return : \n");
		while (tab[i] != 0)
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
*/

/* test de la fonction ft_itoa */
/*	if (argc > 0)
	{	
		printf("ft_itoa return : %s\n", ft_itoa(atoi(argv[1])));
	}
*/

/* test de la fonction ft_putendl_fd */
/*	if (argc > 0)
	{
		printf("ft_putendl_fd return : %s\n", ft_putendl_fd(argv[1], argv[2]));
	}
*/
	return (0);
}
