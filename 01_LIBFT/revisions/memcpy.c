#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char *srci;	
	unsigned char *desti;

	
	i = 0;
	srci = (unsigned char *)src;
	desti = (unsigned char *)dest;
	if (!srci || !desti)
		return (NULL);
	while (srci && i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (desti);
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	char *dest = NULL;
	char *src = NULL;
	int n = 0;


	printf("source : ");
	scanf("%s", src);
	printf("destination : ");
	scanf("%s", dest);
	printf("size : ");
	scanf("%d", &n);
	memcpy(dest, src, n);
	printf("real_function :\n");
	printf("\tdestination after function :\t%s\n", dest);
	printf("ft_function :\n");
	ft_memcpy(dest, src, n);
	printf("\tdestination after function :\t%s\n", dest);
	return (0);
}

