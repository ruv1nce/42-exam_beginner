#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			c = ((argv[1][i] - 64 + 13) % 26);
		   	if (c == 0)
				c = 26;
			c += 64;
			write(1, &c, 1);
		}
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			c = ((argv[1][i] - 96 + 13) % 26);
			if (c == 0)
				c = 26;
			c += 96;
			write(1, &c, 1);
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}
