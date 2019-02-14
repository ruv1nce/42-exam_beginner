#include <unistd.h>
#include <stdio.h> //killme

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c += octet >> i & 1;
		if (i < 7)
			c = c << 1;
		i++;
	}
	return (c);
}

int	main()
{
	printf("%i\n", reverse_bits(136));
	printf("%i\n", reverse_bits(15));
	printf("%i\n", reverse_bits(255));
}
