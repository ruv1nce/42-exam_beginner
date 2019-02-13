#include <unistd.h>

int	check_first_occ(char *str, int cnt)
{
	int	k;

	k = 0;
	while (k < cnt)
	{
		if (str[k] == str[cnt])
			return (1);
		k++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{
				if (check_first_occ(argv[1], i) == 0)
					write(1, &argv[1][i], 1);
				break;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}
