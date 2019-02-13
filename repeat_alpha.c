#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	offset;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		offset = 0;
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			offset = 96;
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			offset = 64;
		if (offset)
		{
			j = 0;
			while (j < (argv[1][i] - offset))
			{
				write(1, &argv[1][i], 1);
				j++;
			}
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n",1);
}
