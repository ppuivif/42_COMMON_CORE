#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit = 0;
	int i = 7;

	while(i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
	write(1, "\n", 1);
}

#include <stdio.h>

int main ()
{
	print_bits(2);
}