

#include <unistd.h>
int	main()
{
	int	i = 8;
	unsigned char octet = 2;
	char bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}

}
