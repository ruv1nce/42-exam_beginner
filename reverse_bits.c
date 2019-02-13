#include <unistd.h>
#include <stdio.h> //killme

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < 7)
	{
		c += octet >> i & 1;
		c = c << 1;
		i++;
	}
	return (c);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", reverse_bits(argv[1][0]));
}
